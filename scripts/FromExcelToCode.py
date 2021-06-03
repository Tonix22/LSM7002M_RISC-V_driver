import pandas as pd

file_errors_location = '/home/tonix/Documents/CINVESTAV/Proyecto_Lime/LMS7002M-driver/Documentation/bydtatype.xlsx'
df = pd.read_excel(file_errors_location)
hex_data = df['HEX OPCODE']
API_types = df.loc[:, 'P1_t':'Return_t']
API_name = df['API Name']
counter = 0


Parms_class = {}


for n in range(len(API_types["P1_t"])):
    parms = ""
    ret_str = ""

    for m in API_types:
        if API_types[m][n] == "None":
            break
        #print (API_types[m][n],end='')
        parms+=str(API_types[m][n])+ ","
    
    ret_str = str(API_types['Return_t'][n])
    if(ret_str != "nan"):
        nametypedef =" "+"callback_"+ str(counter)
        final_str = "typedef "+ret_str+nametypedef+"("+parms[:-1]+")"+";"

        inner_str = "{0x"+str(hex_data[n])+", &"+str(API_name[n])+"},"
        
        if parms[:-1] not in Parms_class:
            Parms_class[parms[:-1]] = [final_str]
            Parms_class[parms[:-1]].append(inner_str)
            counter+=1

        else:
            Parms_class[parms[:-1]].append(inner_str)


for key in Parms_class.keys():
    for M in Parms_class[key]:
        print(M)
    print("****")