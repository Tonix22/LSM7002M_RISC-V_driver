import enum
import os
import csv

class State(enum.Enum):
    exploring = 0
    description_begin = 1
    description_end = 2
    params_sec_description = 3
    return_sec_description = 4
    API_CALL = 5
    Save_to_xls = 6

KeyWord = "LMS7002M_API"

file = "/../coprocessorInt/include/LMS7002M/LMS7002M.h"
path = os.getcwd()+file


with open('LimeAPI.csv', 'w', newline='') as xlsx:
    writer = csv.writer(xlsx)
    header = ["SN", "API Name", "API Description","P1_t","P2_t","P3_t","P4_t","P5_t","P6_t","P1 info","P2 info","P3 info","P4 info","P5 info","P6 info","Return_t", "Return info"]
    writer.writerow(header)

with open(path) as file:
    
    state = State.exploring
    # read the content of the file opened
    content = file.readlines()
    
    #arranged data
    API_metada = []

    #Temporal variables
    serial_number = 1
    API_Name = ""
    API_Description  = ""
    types_idx = 0
    Ptypes      = ["None","None","None","None","None","None"]
    Ptypes_info = ["None","None","None","None","None","None"]
    API_return_type  = "void"
    API_return_info  = "None"

    for i in range(78,len(content)):

        if '/*!' in content[i] and state == State.exploring:
            state = State.description_begin

        elif '\\param' in content[i] and state == State.description_begin:
            state = State.description_end
            #save description
            state = State.params_sec_description
        elif '\\return' in content[i] and state == State.params_sec_description:
            #save params section description
            state = State.return_sec_description
        elif '*/' in content[i]:
            #save return section description
            state = State.API_CALL
            continue
        elif state == State.API_CALL:
            
            API_line = content[i]

            #return type
            word_begin =  API_line.find(KeyWord)+len(KeyWord)+1 # 1 is for space 
            word_end   =  API_line.find(" ",word_begin)
            #print(API_line[word_begin:word_end])
            API_return_type = API_line[word_begin:word_end]
            word_end+=1

            #API name 
            word_begin =  word_end
            word_end   =  API_line.find("(",word_begin)
            API_Name   =  API_line[word_begin:word_end]
            #print(API_line[word_begin:word_end])
            word_end+=1 #avoid (

            #Params

            # Get all paramter string with type and name
            types_idx = 0
            while(1):
                Param_begin =  word_end
                Param_end   =  API_line.find(",",Param_begin)
                if(Param_end == -1):
                    Param_end   =  API_line.find(")",Param_begin)
                if(content[i][Param_begin]==';' or Param_end == -1):
                    break
                #look a reverse find to get the param name
                word_begin = API_line.rfind("*",Param_begin,Param_end)+1
                P_type_end = word_begin

                if(word_begin == 0):
                    word_begin = API_line.rfind(" ",Param_begin,Param_end)+1
                    P_type_end = word_begin

                #assign corresponding indexes
                word_end = Param_end
                P_type_begin = Param_begin
                
                #print(API_line[P_type_begin:P_type_end])
                #print(API_line[word_begin:word_end])

                Ptypes[types_idx]      = API_line[P_type_begin:P_type_end]
                Ptypes_info[types_idx] = API_line[word_begin:word_end]
                types_idx+=1
                word_end+=1
            state = State.Save_to_xls

        #save data in csv file
        if (state == State.Save_to_xls):
            API_metada.append(serial_number)
            API_metada.append(API_Name)
            API_metada.append(API_Description)
            API_metada.append(Ptypes[0])
            API_metada.append(Ptypes[1])
            API_metada.append(Ptypes[2])
            API_metada.append(Ptypes[3])
            API_metada.append(Ptypes[4])
            API_metada.append(Ptypes[5])
            API_metada.append(Ptypes_info[0])
            API_metada.append(Ptypes_info[1])
            API_metada.append(Ptypes_info[2])
            API_metada.append(Ptypes_info[3])
            API_metada.append(Ptypes_info[4])
            API_metada.append(Ptypes_info[5])
            API_metada.append(API_return_type)
            API_metada.append(API_return_info)
            with open('LimeAPI.csv', 'a+', newline='') as xlsx:
                writer = csv.writer(xlsx)
                writer.writerow(API_metada)

            API_metada.clear()
            API_Name = ""
            API_Description  = ""
            types_idx = 0
            Ptypes      = ["None","None","None","None","None","None"]
            Ptypes_info = ["None","None","None","None","None","None"]
            API_return_type  = "void"
            API_return_info  = "None"
            
            serial_number+=1
            state = State.exploring
            continue

        if(state != State.exploring):
            data = content[i][content[i].find("*")+2:]

        if (state == State.description_begin):
            API_Description+=data

        if (state == State.params_sec_description):
            data = data[content[i].find(" ")+1:]
            Ptypes_info[types_idx] = data
            types_idx+=1
            #print (data)

        if (state == State.return_sec_description):
            data = data[content[i].find(" ")+1:]
            API_return_info = data
           #print (data)
