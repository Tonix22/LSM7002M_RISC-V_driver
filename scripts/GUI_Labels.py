import pandas as pd
import numpy as np

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



helper = GUI_Helper_generator()
helper.Generate_cha_dir_vector()
#helper.generate_QT_labels_enum()
#helper.generate_QT_labels_string()
#helper.generate_submenus()
"""
for n in QT_labels:
    rslt_df = df[df['QT Label'] == n]
    print(n, end='')
    print(rslt_df['HEX OPCODE'].to_string(index=False))
"""