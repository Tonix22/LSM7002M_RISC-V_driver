import pandas as pd
import os
import re

def generate_header_guard(filename):
    # Convert filename to uppercase and replace non-alphanumeric characters with underscore
    guard = re.sub(r'\W+', '_', filename.upper())
    return guard

def generate_typedefs(excel_file, output_file):
    # Read the Excel file
    df = pd.read_excel(excel_file)
    
    # Check that required columns exist
    if "Typedef" not in df.columns or "Group Name" not in df.columns:
        print("Error: Excel file must contain 'Typedef' and 'Group Name' columns.")
        return

    header_guard = generate_header_guard(os.path.basename(output_file))

    # Open the output file for writing the auto-generated C code
    with open(output_file, 'w') as f:
        # Write header guard opening lines
        f.write(f"#ifndef {header_guard}\n")
        f.write(f"#define {header_guard}\n\n")
        
        # Write constant header includes
        f.write('#include "LMS7002M.h"\n')
        f.write('#include "parser.h"\n')
        f.write('#include "LMS7002M_filter_cal.h"\n\n')
        
        # Process each row where a typedef is defined
        for index, row in df.iterrows():
            typedef_name = row["Typedef"]
            group_name = row["Group Name"]
            if pd.notna(typedef_name):
                typedef_name = str(typedef_name).strip()
                group_name = str(group_name).strip() if pd.notna(group_name) else ""
                
                # Write Doxygen-style header comment for the typedef
                f.write("/**\n")
                f.write(" * @typedef {0}\n".format(typedef_name))
                f.write(" * Callback typedef for {0}\n".format(group_name))
                f.write(" */\n")
                # Write the typedef declaration (using a fixed pattern)
                f.write("typedef LMS7002M_t* {0}(LMS7002M_spi_transact_t);\n\n".format(typedef_name))
        
        # Write closing header guard
        f.write(f"#endif /* {header_guard} */\n")
    
    print("Typedefs generated in file:", output_file)


def sanitize_identifier(name):
    """Generate a valid identifier from a given name."""
    sanitized = re.sub(r'\W+', '_', name)
    return sanitized

def generate_opcode_descriptors(excel_file, output_file):
    # Read the Excel file
    df = pd.read_excel(excel_file)
    
    # Filter out rows that contain "****" in any cell
    df = df[~df.apply(lambda row: row.astype(str).str.contains(r'\*{4}').any(), axis=1)]
    
    # Required columns for opcode descriptor generation
    required_cols = [
        "Group Name",    # This will be used as the group identifier (enum constant)
        "HEX OPCODE",    # The opcode value (e.g. "A1" or "0xA1")
        "QT Label",      # API name (string)
        "P0_t", "P1_t", "P2_t", "P3_t", "P4_t", "P5_t",  # Parameter types
        "Callback"       # Callback function name
    ]
    for col in required_cols:
        if col not in df.columns:
            print("Error: Excel file must contain columns:", required_cols)
            return
    
    # Group the DataFrame by "Group Name"
    groups = df.groupby("Group Name")
    
    # We'll collect info for each group to generate the aggregated array later.
    group_info_list = []
    
    with open(output_file, 'w') as f:
        # Write header includes and necessary additional headers
        f.write('#include "parser_typedefs.h"\n')
        f.write('#include "parser.h"\n')
        f.write('#include "Geric_Parameter.h" // Ensure Geric_Parameter is defined\n')
        f.write('#include "opcode_constants.h" // Ensure opcode constants are defined\n\n')
        
        f.write("/* Auto-generated file: Grouped OpcodeDescriptor arrays and aggregated descriptores array */\n\n")
        
        # For each unique group, generate an array of OpcodeDescriptor
        for group_name, group_df in groups:
            sanitized_group = sanitize_identifier(group_name)
            array_name = f"{sanitized_group}_opcodes"
            f.write(f"/* Opcode descriptors for group {group_name} */\n")
            f.write(f"OpcodeDescriptor {array_name}[] = {{\n")
            
            for index, row in group_df.iterrows():
                hex_opcode = str(row["HEX OPCODE"]).strip()
                # Ensure the opcode is a valid hex literal (prepend "0x" if needed)
                if not hex_opcode.lower().startswith("0x"):
                    hex_opcode = "0x" + hex_opcode
                qt_label = str(row["QT Label"]).strip()
                callback = (str(row["Callback"]).strip() 
                            if pd.notna(row["Callback"]) and str(row["Callback"]).strip() not in ["", "None"]
                            else "NULL")
                
                # Process parameter columns: only include those that are not None
                param_cols = ["P0_t", "P1_t", "P2_t", "P3_t", "P4_t", "P5_t"]
                param_types_list = []
                for col in param_cols:
                    value = row[col]
                    if pd.notna(value):
                        value_str = str(value).strip()
                        if value_str and value_str.lower() != "none":
                            param_types_list.append(value_str)
                num_params = len(param_types_list)
                comment_hint = ", ".join(param_types_list) if param_types_list else "none"
                
                f.write("    {\n")
                # Note: .group field is removed from individual initializers.
                f.write("        .opcode = {0},\n".format(hex_opcode))
                f.write("        .QT_Label = \"{0}\",\n".format(qt_label))
                f.write("        .num_params = {0},\n".format(num_params))
                # .args is set to NULL with a comment that hints at the parameter types
                f.write("        .args = NULL; // " + comment_hint + "\n")
                f.write("        .callback = (void*){0}\n".format(callback))
                f.write("    },\n")
            
            f.write("};\n\n")
            # Save the group info for the aggregated array:
            group_info_list.append((group_name, array_name))
        
        # Generate the aggregated grouping array
        # Assuming a structure DescriptorGroup is defined in your headers
        f.write("/* Aggregated grouped opcode descriptors */\n")
        f.write("DescriptorGroup descriptores[] = {\n")
        for group_name, array_name in group_info_list:
            # The .group field is set to the enum constant (as provided in Group Name)
            f.write("    {{ .group = {0}, .descriptors = {1}, .num_descriptors = sizeof({1})/sizeof(OpcodeDescriptor) }},\n".format(group_name, array_name))

        f.write("};\n\n")
        
        # Write an opcode filter function that searches across all groups
        f.write("OpcodeDescriptor* getOpcodeDescriptor(uint32_t opcode) {\n")
        f.write("    int i, j;\n")
        f.write("    int numGroups = sizeof(descriptores) / sizeof(DescriptorGroup);\n")
        f.write("    for (i = 0; i < numGroups; i++) {\n")
        f.write("        DescriptorGroup group = descriptores[i];\n")
        f.write("        int numOpcodes = group.num_descriptors;\n")
        f.write("        for (j = 0; j < numOpcodes; j++) {\n")
        f.write("            if (group.descriptors[j].opcode == opcode) {\n")
        f.write("                return &group.descriptors[j];\n")
        f.write("            }\n")
        f.write("        }\n")
        f.write("    }\n")
        f.write("    return NULL;\n")
        f.write("}\n")
    
    print("Opcode descriptors generated in file:", output_file)



if __name__ == '__main__':
    # Build the file path relative to this script's location
    script_dir = os.path.dirname(os.path.abspath(__file__))
    excel_file = os.path.abspath(os.path.join(script_dir, "../../../Documentation/AutoGen/AutoGenCode.xlsx"))
    # Output header file name
    output_file = "parser_typedefs.h"
    generate_typedefs(excel_file, output_file)
    
    # Output C source file name (for example, "parser_opcodes.c")
    output_file = "parser_opcodes.c"
    generate_opcode_descriptors(excel_file, output_file)
