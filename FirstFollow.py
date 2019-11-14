productions=[]
tempProd=[]
nterminals=[]
extra=[]
first={}

follow={}

n = int(input("Number of Grammers: "))
for i in range (0,n):
    gr= input("")
    x=gr[3:].split("|")
    for j in x:
        productions.append(gr[:3]+j)
        tempProd.append(gr[:3]+j)
for i in productions:
    print(i)


# productions=["S->(A)","S->$","A->TE","E->&TE","E->$","T->(A)","T->a","T->b","T->c",]
# productions=["S->aSe","S->B","B->bBCf","B->C","C->cCg","C->d","C->#",]
# productions=["P->i","P->c","P->nTs","Q->P","Q->aS","Q->bSc","R->b","R->$","S->c","S->Rn","S->$","T->RSq",]
# productions=["E->TX","X->+TX","X->#","T->FY","Y->*FY","Y->#","F->(E)","F->i",]

#--------------------------------------
# tempProd=["S->(A)","S->$","A->TE","E->&TE","E->$","T->(A)","T->a","T->b","T->c",]
# tempProd=["S->aSe","S->B","B->bBCf","B->C","C->cCg","C->d","C->#",]
# tempProd=["P->i","P->c","P->nTs","Q->P","Q->aS","Q->bSc","R->b","R->$","S->c","S->Rn","S->$","T->RSq",]
# tempProd=["E->TX","X->+TX","X->#","T->FY","Y->*FY","Y->#","F->(E)","F->i",]


#sort lowercase first
print("Sorting")
productions.sort(key=lambda p: p[3].lower())
[print(i) for i in productions]
    
print("\nNon Terminals:")
for i in productions: 
    if i[0] not in nterminals: 
        nterminals.extend(i[0])
[print(i) for i in nterminals]
    

print("\nInitial Dictionaries:")
for i in range(0,len(nterminals)): 
        first[nterminals[i]]=[]
[print(f"{i}:{j}") for i,j in first.items()]
    
#for terminal symbols
for i in range(0,len(nterminals)):
    for j in range(0,len(productions)):
        if nterminals[i]==productions[j][0]:
            if((productions[j][3].isupper()==False) or productions[j][3]=="#"):
                first[nterminals[i]].extend(productions[j][3])
                
# print("\nAfter appending terminals:")
# [print(f"{i}:{j}") for i,j in first.items()]
    

#List out productions starting with a Non-Terminal
print("productions starting with a Non-Terminal")
[extra.append(i) for i in productions if i[3].isupper()]
[print(i) for i in extra]

for z in range(3):  
    # print("\nAfter appending terminals:")
    # [print(f"{i}:{j}") for i,j in first.items()]
    for i in range(0,len(extra)):
        count=0
        for j in extra[i][3:]:    
            count+=1    
            if j.isupper() and count==len(extra[i][3:]):
                first[extra[i][0]].extend(first[j])
                break 
                        
            if j.isupper():    
                if '#' in first[j]:     
                    first[j].remove('#')
                    first[extra[i][0]].extend(first[j])
                    first[j].extend('#')
                elif '#' not in first[j]:                          
                    first[extra[i][0]].extend(first[j])
                    break                  
            elif j.isupper()==False:
                first[extra[i][0]].extend(j)
                break  


#To Uniquely Identify
for i in first.keys():
    first[i]=list(set(first[i])) 
                                        
print("\nFirst FUnction:")
[print(f"First({i})={j}") for i,j in first.items()]




#--------------------------------FOLLOW FUNCTION---------------------------------
nterminals2=[]
# print("\nNon Terminals:")
for i in tempProd: 
    if i[0] not in nterminals2: 
        nterminals2.extend(i[0])
# [print(i) for i in nterminals2]

# print("\n\nInitial Follow Dictionary:")
for i in range(0,len(nterminals2)): 
    follow[nterminals2[i]]=[]
# [print(f"{i}:{j}") for i,j in follow.items()]


# print("Main Follow:")
#CASE-0:Initial case:
follow[tempProd[0][0]].extend('$')

#CASE-1: If follower is a terminal.-----------------------------------------
for i in range(0,len(tempProd)):     # productions[i]
    temp=0
    flag=0
    for k in tempProd[i][3:]:
        if k.isupper()==False and flag==1:
           follow[temp].extend(k)
           break
        if k.isupper():
            temp=k
            flag=1
#----------------------------------1--------------------------------

# print("Terminal:")
# for i in follow.keys():
#     follow[i]=list(set(follow[i])) 
# print("\nFollw FUnction:")
# [print(f"Follow({i})={j}") for i,j in follow.items()]

#CASE-2: If follower is none. (No Follower)--------------------------------
for i in range(0,len(tempProd)):     # productions[i]
    count=0
    for k in tempProd[i][3:]:
        count+=1
        if k.isupper() and count==len(tempProd[i][3:]):
            follow[k].extend(follow[tempProd[i][0]])

#-----------------------------2-------------------------------------------

# print("No Follower: 1st")
# for i in follow.keys():
#     follow[i]=list(set(follow[i])) 
# print("\nFollw FUnction:")
# [print(f"Follow({i})={j}") for i,j in follow.items()]


#CASE-3: If follower is a Non-Terminal----------------------------------------
for z in range(3):
    for i in range(0,len(tempProd)):     # productions[i]
        temp=0
        flag=0
        count=0
        for k in tempProd[i][3:]:
            count+=1
            if k.islower() and flag==2:
                follow[temp].extend(k)    
            if k.isupper() and flag==1:
                if '#' in first[k]:
                    first[k].remove('#')
                    follow[temp].extend(first[k])
                    first[k].extend('#')
                    flag=2
                    if count == len(tempProd[i][3:]):
                        # follow[temp].extend(follow[k])
                        # print(tempProd[0][0])
                        follow[temp].extend(follow[tempProd[i][0]])
                    continue
                elif '#' not in first[k]:                          
                    follow[temp].extend(first[k])
                    break
            # print(count)
            # if k.isupper() and count==len(tempProd[i][3:]):
            #     # follow[temp].extend(first[k])
            #     print(count)
            if k.isupper():
                temp=k #to work with it in next iter
                flag=1
#---------------------------------------3---------------------

# print("\n\nNon Terminal:")
# for i in follow.keys():
#     follow[i]=list(set(follow[i])) 
# print("Follw FUnction:")
# [print(f"Follow({i})={j}") for i,j in follow.items()]


#CASE-2: If follower is none. (No Follower)-----------------------------------
for i in range(0,len(tempProd)):     # productions[i]
    count=0
    for k in tempProd[i][3:]:
        count+=1
        if k.isupper() and count==len(tempProd[i][3:]):
            follow[k].extend(follow[tempProd[i][0]])
#-----------------------------2-----------------------------------------------


#To Uniquely Identify
for i in follow.keys():
    follow[i]=list(set(follow[i])) 
print("\n_________________Follw FUnction___________________")
[print(f"Follow({i})={j}") for i,j in follow.items()]