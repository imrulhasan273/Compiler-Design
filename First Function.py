
#Imrul Hasan
#CSE,UAP--16101034
production=[]
n = int(input("How many grammers you want to add- \n"))
for i in range (0,n):
    s= input("")
    a=s[3:].split("|")
    for j in a:
        production.append(s[:3]+j)

#production=["P->i","P->c","P->nTs","Q->P","Q->aS","Q->bSc","R->b","R->$","S->c","S->Rn","S->$","T->RSq",]

#identify terminals and list out them
terminals=[]
for i in production:
    if i[0] not in terminals:
        terminals.append(i[0])

#make dic for terminals and initialize with and empty list
dic={}
for j in range(0,len(terminals)):
    dic[terminals[j]]=[]

#inserting non terminals and $ which is in index 3
for j in range(0,len(production)):
     if(production[j][3].islower() or production[j][3]=='$'):
         dic[production[j][0]].append(production[j][3])

#print(dic)
#List out which start with a Terminal symbols

headche=[]     
for i in production:
    if i[3].isupper():
        headche.append(i)
           
#print(headche)

flag=True
for i in headche:
    flag=True
    for j in i[3:]:                 #start a loop from after  '->'
        if j.isupper() and flag:    #if Terminal then append its FF except $ and cont.
            if '$' in dic[j]:       #checking $ if exist remove and append rest
                dic[j].remove('$')
                dic[i[0]].extend(dic[j])
                dic[j].append('$')
            else:                           # if $ not exists append all
                dic[i[0]].extend(dic[j])
                flag=False                  # it will not continue with rest
        if j.islower() and flag:            # lower case found and flag =true
            dic[i[0]].append(j)
            flag=False                            # append it and make flag=false
                                             
#print(dic)
#Remove Duplicates using 'set' that removes duplicates
for i in dic.keys():
    dic[i]=list(set(dic[i]))
    
for i in dic.keys():
    print("First Function ({}) = {}".format(i,dic[i]))

#.
#production=["A->Bc","A->qC","A->r","B->$","B->cdF","B->A","C->DE","C->$","C->BnC","D->$","D->BC","E->aB","E->Ct"]

#Link: https://ideone.com/4mjJ8u
    



