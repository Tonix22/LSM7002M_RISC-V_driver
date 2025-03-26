#!/usr/bin/env python3
import pandas as pd
import re

def sanitize_for_c_identifier(name: str) -> str:
    """
    Intenta sanitizar el nombre para que sea un identificador válido en C.
    Si el nombre es 'LMS7002M_create', no hay problema.
    Quita espacios, etc.
    """
    # Reemplaza los caracteres no válidos por '_'
    return re.sub(r'[^a-zA-Z0-9_]', '_', name)

def generate_parser_c(bydtype_file, description_file, output_c="parser_autogen.c"):
    """
    Lee bydtatype2.xlsx y LimeAPI_descruption.xlsx.
    Genera parser_autogen.c siguiendo la estructura dada:

    - Cada QT Label => un arreglo 'Caller NombreLabel[] = {...};'
    - Cada entrada => puntero a función &APIName con un comentario multilinea con opcode + desc.
    - Al final un 'Caller* Group[...] = {...};' con todas las references.
    """

    # 1) Cargar DataFrames
    df_main = pd.read_excel(bydtype_file)
    df_desc = pd.read_excel(description_file)

    # 2) Eliminar filas con '***' si aplica
    mask_bad = df_main.apply(lambda row: row.astype(str).str.contains(r'\*\*\*').any(), axis=1)
    df_main = df_main[~mask_bad].copy()

    # 3) Merge por 'API Name' para traer la descripción
    merged = pd.merge(
        df_main,
        df_desc[['API Name','API Description']],
        on='API Name',
        how='left'
    )

    # 4) Agrupar por 'QT Label'
    grouped = merged.groupby('QT Label')

    # 5) Generar el archivo .c
    with open(output_c, "w", encoding="utf-8") as f:
        # Encabezado
        f.write('#include \"LMS7002M.h\"\n')
        f.write('#include \"parser.h\"\n')
        f.write('#include \"LMS7002M_filter_cal.h\"\n\n')
        f.write('Geric_Parameter Params[MAX_PARAMETERS];\n\n')

        # Ejemplo de typedefs ya existen en parser.h. Insertamos si hace falta
        f.write('// Si necesitas typedefs, colócalos aquí.\n\n')

        # Guardar array names para luego componer un Group[]
        array_names = []

        for qt_label, group_data in grouped:
            # Normalizar para nombre de arreglo
            arr_name = sanitize_for_c_identifier(qt_label)
            if not arr_name:
                arr_name = "UNKNOWN"

            array_names.append(arr_name)

            # Encabezado del array
            f.write(f"// ---- {qt_label} ----\n")
            f.write(f"// (Auto-generated array for QT Label \"{qt_label}\")\n")
            f.write(f"Caller {arr_name}[] = \n{{\n")

            # Ordenar p.ej. por HEX OPCODE
            group_sorted = group_data.sort_values(by='HEX OPCODE', key=lambda col: col.map(lambda x: int(str(x).replace('0x',''), 16) if isinstance(x,str) else 999999))

            for _, row in group_sorted.iterrows():
                opcode_hex = str(row['HEX OPCODE'])
                api_name = str(row['API Name'])
                description = str(row.get('API Description', 'No description'))

                # El puntero a función se asume = &APIName
                # OJO: si api_name tiene caracteres inválidos, habría que sanitizar más
                function_ptr = "&" + api_name

                # Bloque de comentario multilinea
                f.write("    /*\n")
                f.write(f"     * OPCODE: {opcode_hex}\n")
                f.write(f"     * API Name: {api_name}\n")
                f.write(f"     * Description: {description}\n")
                f.write("     */\n")

                f.write(f"    {{ {function_ptr} }},\n\n")

            f.write("};\n\n")

        # 6) Generar un 'Caller* Group[...]' a modo de ejemplo
        f.write("// Example final Group referencing each array:\n")
        f.write("Caller* Group[OPCODE_SIZE] = {\n")
        for idx, arr_name in enumerate(array_names):
            f.write(f"    &{arr_name}[0], // index={idx} from QT Label\n")
        f.write("};\n\n")

        f.write("// End of auto-generated file\n")

    print(f"Archivo '{output_c}' generado con éxito.")

if __name__ == "__main__":
    bydtype2_path = '/home/tonix/Documents/LSM7002M_RISC-V_driver/Documentation/bydtatype2.xlsx' # Ajusta rutas reales
    limeapi_path = '/home/tonix/Documents/LSM7002M_RISC-V_driver/Documentation/LimeAPI_descruption.xlsx'
    out_file = "parser_autogen.c"

    generate_parser_c(bydtype2_path, limeapi_path, out_file)
