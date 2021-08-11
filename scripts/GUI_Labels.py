import pandas as pd
import numpy as np

class GUI_Helper_generator():
    def __init__(self):
        self.df = pd.read_excel('../Documentation/bydtatype.xlsx')
        self.df = self.df.dropna()
        self.QT_labels = self.df['QT Label'].unique()

    def generate_QT_labels_enum(self):
        final_str = "typedef enum\r\n{\r\n"
        for n in self.QT_labels:
            n = n.replace(" ","_") # hola mundo Hola_mundo
            final_str+="\t"+n+"_num,\r\n"
        final_str+="\tQt_labels_size\r\n}Qt_label_t;\r\n"
        return final_str

    def generate_QT_labels_string(self):
        final_str ="#define QT_LABELS_COLLECTION   "
        padding   = len(final_str)
        first     = True
        for n in self.QT_labels:
            if(first):
                first = False
                final_str+="PUSH_TO_LIST(\""+n+"\""+")"+"\\\r\n"
            else:
                final_str+=padding*" "+"PUSH_TO_LIST(\""+n+"\""+")"+"\\\r\n"
        return final_str

    def gen_function_type_header(self):
        header = "#include \"common.h\"\r\n\r\n"
        header += self.generate_QT_labels_enum() + "\r\n"
        header += self.generate_QT_labels_string()
        header += "#endif"
        print(header, file=open('function_type.h', 'a'))

    def generate_submenus(self):
        final_str = ""
        for n in self.QT_labels:
            define_str = "#define "+n.replace(" ","_").upper()+"_SUBMENU_COLLECTION "
            size_define = len(define_str)
            final_str+=define_str

            rslt_df = self.df[self.df['QT Label'] == n]
            Api_names = rslt_df['API Name'].to_string(index=False).replace("LMS7002M_","")
            Api_names = Api_names.replace(" ","")
            Api_names = Api_names.split('\n')
            first = True

            for m in range(0,len(Api_names)):
                if(first):
                    first = False
                    final_str+="PUSH_TO_LIST(\""+Api_names[m]+"\")"+"\\\r\n"
                else:
                    final_str+=size_define*" "+"PUSH_TO_LIST(\""+Api_names[m]+"\")"+"\\\r\n"
            
            final_str = final_str[:-3]
            final_str+="\r\n\r\n"

        print(final_str, file=open('submenus.h', 'a'))

    def gerenate_submenus_enums(self):
        for n in self.QT_labels:
            print("typedef enum{", file=open('submenus.h', 'a'))
            rslt_df = self.df[self.df['QT Label'] == n]
            Api_names = rslt_df['API Name'].to_string(index=False).replace("LMS7002M_","")
            Api_names = Api_names.replace(" ","")
            Api_names = Api_names.split('\n')
            first = True
            for m in range(0,len(Api_names)):
                if(m == (len(Api_names)-1)):
                    print("\t"+Api_names[m][0].upper()+Api_names[m][1:]+"_submenu_num,", file=open('submenus.h', 'a'))
                else:
                    if(first):
                        first = False
                        print("\t"+Api_names[m][0].upper()+Api_names[m][1:]+"_submenu_num,", file=open('submenus.h', 'a'))
                    else:
                        print("\t"+Api_names[m][0].upper()+Api_names[m][1:]+"_submenu_num,", file=open('submenus.h', 'a'))
            print("\t"+n.replace(" ","_")+"_submenu_size", file=open('submenus.h', 'a'))
            print("}"+n.replace(" ","_")+"_num_t;", file=open('submenus.h', 'a'))
            print("", file=open('submenus.h', 'a'))

    def write_submenus_file(self):
        print("#include \"common.h\"\r\n", file=open('submenus.h', 'a'))
        self.gerenate_submenus_enums()
        self.generate_submenus()

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

    def Generate_cha_dir_vector(self):
        print("std::vector<std::pair<bool,bool>> enable_ch_dir[Qt_labels_size]={")
        """
        P_labels = self.df['P1_t'].unique()
        P_labels = ("\n".join(P_labels)).replace(" ","").split('\n')
        """
        P_Filter = ["constLMS7002M_chan_t","constLMS7002M_dir_t"]
        for n in self.QT_labels:
            rslt_df = self.df[self.df['QT Label'] == n]
            
            p1 = rslt_df['P1_t'].to_string(index=False)
            p2 = rslt_df['P2_t'].to_string(index=False)
            p1 = p1.replace(" ","")
            p2 = p2.replace(" ","")
            p1 = p1.split('\n')
            p2 = p2.split('\n')
            chan = np.array([ x == P_Filter[0] for x in p1]) | np.array([ x == P_Filter[0] for x in p2])
            dir  = np.array([ x == P_Filter[1] for x in p1]) | np.array([ x == P_Filter[1] for x in p2])
            #print (n+": ",end='')
            first = True
            print("\t",end='')
            print("{",end='')
            if(len(chan) == 1):
                print("{",end='')
            for m in range(0,len(chan)):
                if(m == (len(chan)-1)):
                    print("{"+str(chan[m]).lower()+","+str(dir[m]).lower()+"}",end='')
                    print("}",end='')
                else:
                    if(first):
                        first = False
                        print("{",end='')
                        print("{"+str(chan[m]).lower()+","+str(dir[m]).lower()+"},",end='')
                    else:
                        print("{"+str(chan[m]).lower()+","+str(dir[m]).lower()+"},",end='')
            #
            #print (chan)
            print("},")
        print("};")

    def Generate_descriptions(self):
        Description_excel = pd.read_excel('../Documentation/byKeyword.xlsx')
        print("#ifndef DESCRIPTION_H \r\n#define DESCRIPTION_H \r\n ", file=open('description.h', 'a'))
        
        print("#include \"description.h\"",file=open('description.cpp', 'a'))
        print("#include <vector>",file=open('description.cpp', 'a'))
        print("#include <mainwindow.h>\r\n",file=open('description.cpp', 'a'))
        print("std::vector<const char*> info[Qt_labels_size]=\r\n{",file=open('description.cpp', 'a'))
        final_vector = ""
        for n in self.QT_labels:
            rslt_df = self.df[self.df['QT Label'] == n]
            API_NAME = rslt_df['API Name'].to_string(index=False).replace(" ","")
            API_NAME = API_NAME.split('\n')
            vector_string = ""
            for n in API_NAME:
                val = Description_excel.index[Description_excel['API Name']==n][0]
                description = Description_excel['API Description'][val][1:]
                description = description.replace('\n','\\r\\n\\\n')
                define_name = n.upper() + "_DESCRIPTION()"
                description = "#define "+ define_name+ " \""+ description[:-2] + "\"\n"
                
                vector_string += define_name+","
                print(description, file=open('description.h', 'a'))
            
            vector_string = "\t{{"+vector_string[:-1]+"}},\r\n"
            final_vector  +=vector_string
        
        final_vector = final_vector[:-3]+"\r\n};"
        print(final_vector,file=open('description.cpp', 'a'))
        print("#endif", file=open('description.h', 'a'))

helper = GUI_Helper_generator()
#helper.gen_function_type_header()
helper.write_submenus_file()
#helper.Generate_descriptions()
"""
for n in QT_labels:
    rslt_df = df[df['QT Label'] == n]
    print(n, end='')
    print(rslt_df['HEX OPCODE'].to_string(index=False))
"""