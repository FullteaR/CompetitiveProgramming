s1=input()
s2=input()

table=[[0 for i in range(len(s1)+1)] for j in range(len(s2)+1)]


for j in range(len(s2)+1):
    table[j][0]=j
for i in range(len(s1)+1):
    table[0][i]=i


for i in range(1,len(s1)+1):
    for j in range(1,len(s2)+1):
        if s1[i-1]==s2[j-1]:
            table[j][i]=min(table[j-1][i]+1,table[j][i-1]+1,table[j-1][i-1])
        else:
            table[j][i]=min(table[j-1][i],table[j][i-1],table[j-1][i-1])+1



print(table[-1][-1])
