import pandas as pd

df = pd.read_csv("LimeAPI.csv")
API_names = df['API Name']
API_types = df.loc[:, 'P1_t':'P6_t']
return_type = df['Return_t']

KewWords = {}

for n in range(len(API_types["P1_t"])):
    string = ""
    for m in API_types:
        string += API_types[m][n]+", "
    
    string+=return_type[n]

    if string not in KewWords:
        KewWords[string] = [API_names[n]]
    else:
        KewWords[string].append(API_names[n])


counter = 0

for key in KewWords.keys():

    for m in KewWords[key]:
        renglon = API_names[API_names  == m].index.tolist()
        print(renglon,end=',')
        temp = df.iloc[renglon].loc[:, :'P6_t']
        temp['ClusterID'] = counter
        temp.to_csv('bydtatype.csv', mode='a', index=False, header=False)
    #types.append(pd.Series(), ignore_index=True)
    
    counter+=1
    a = open("bydtatype.csv","a")
    a.write("****,"*10)
    a.write("\n")
    a.close()
    print("")


"""
KewWords = {}

for n in API_names:
    item = n[9:]
    idx = item.find("_")
    item = item[:idx]

    if item not in KewWords:
        KewWords[item[:idx]] = [n]
    else:
        KewWords[item[:idx]].append(n)


counter = 0
for key in KewWords.keys():
    for m in KewWords[key]:
        renglon = API_names[API_names  == m].index.tolist()
        temp = df.iloc[renglon].loc[:, :'P6_t']
        temp['ClusterID'] = counter
        temp.to_csv('byKeyword.csv', mode='a', index=False, header=False)
    counter+=1
    a = open("byKeyword.csv","a")
    a.write("****,"*10)
    a.write("\n")
    a.close()
"""