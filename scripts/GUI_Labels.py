import pandas as pd

class GUI_Helper_generator():
    def __init__(self):
        self.df = pd.read_excel('../Documentation/bydtatype.xlsx')
        self.df = self.df.dropna()
        self.QT_labels = self.df['QT Label'].unique()

    def generate_QT_labels_enum(self):
        for n in self.QT_labels:
            print(n+"_num,")

    def generate_QT_labels_string(self):
        for n in self.QT_labels:
            print("\""+n+"\""+","+"\\")

    def generate_submenus(self):
        for n in self.QT_labels:
            print("#define "+n.upper()+"_SUBMENU_COLLECTION() ", end='')
            rslt_df = self.df[self.df['QT Label'] == n]
            Api_names = rslt_df['API Name'].to_string(index=False).replace("LMS7002M_","")
            Api_names = Api_names.replace(" ","")
            Api_names = Api_names.split('\n')
            first = True
            for m in range(0,len(Api_names)):
                if(m == (len(Api_names)-1)):
                    print("\t\tPUSH_TO_LIST(\""+Api_names[m]+"\")")
                else:
                    if(first):
                        first = False
                        print("PUSH_TO_LIST(\""+Api_names[m]+"\")"+"\\")
                    else:
                        print("\t\tPUSH_TO_LIST(\""+Api_names[m]+"\")"+"\\")
            print()

    def gerenate_submenus_enums(self):
        for n in self.QT_labels:
            print("typedef enum{")
            rslt_df = self.df[self.df['QT Label'] == n]
            Api_names = rslt_df['API Name'].to_string(index=False).replace("LMS7002M_","")
            Api_names = Api_names.replace(" ","")
            Api_names = Api_names.split('\n')
            first = True
            for m in range(0,len(Api_names)):
                if(m == (len(Api_names)-1)):
                    print("\t"+Api_names[m][0].upper()+Api_names[m][1:]+"_num,")
                else:
                    if(first):
                        first = False
                        print("\t"+Api_names[m][0].upper()+Api_names[m][1:]+"_num,")
                    else:
                        print("\t"+Api_names[m][0].upper()+Api_names[m][1:]+"_num,")
            print("\t"+n+"_size")
            print("}"+n+"_num_t;")
            print()
    def Generate_vector(self):
        print("std::vector<int> opcode[Qt_labels_size]={")
        for n in self.QT_labels:
            rslt_df = self.df[self.df['QT Label'] == n]
            opcode = rslt_df['HEX OPCODE'].to_string(index=False)
            opcode = opcode.replace(" ","")
            opcode = opcode.split('\n')
            first = True
            print("\t",end='')
            if(len(opcode) == 1):
                print("{{0x"+opcode[0]+"}},",end='')
            else:
                for m in range(0,len(opcode)):
                    if(m == (len(opcode)-1)):
                        print("0x"+opcode[m],end='')
                        print("}},",end='')
                    else:
                        if(first):
                            first = False
                            print("{{",end='')
                            print("0x"+opcode[m]+",",end='')
                        else:
                            print("0x"+opcode[m]+",",end='')
            print()
        print("};")
helper = GUI_Helper_generator()
helper.Generate_vector()
#helper.generate_QT_labels_enum()
#helper.generate_QT_labels_string()
#helper.generate_submenus()
"""
for n in QT_labels:
    rslt_df = df[df['QT Label'] == n]
    print(n, end='')
    print(rslt_df['HEX OPCODE'].to_string(index=False))
"""