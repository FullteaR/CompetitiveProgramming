L=int(input())
islands=[]
distances=[]
d=0
island=[]
for i in range(L):
    a=int(input())
    if islands==[] and island==[] and a==0:
        continue
    if a!=0:
        island.append(a)
        if d!=0:
            distances.append(d)
        d=0
    else:
        if island!=[]:
            islands.append(island)
        island=list()
        d+=1

if island!=[]:
    islands.append(island)
print(islands)
print(distances)
