import bisect

keys=[]

q=int(input())
d={}

def find(x):
    index=bisect.bisect_left(keys,x)
    if index==len(keys):
        return -1
    if keys[index]==x:
        return index
    else:
        return -1


for _ in range(q):
    query=input().split(" ")
    if query[0]=="0":
        if find(query[1])!=-1:
            pass
        else:
            bisect.insort_left(keys, query[1])
        d[query[1]]=query[2]
    elif query[0]=="1":
        if find(query[1])!=-1:
            print(d[query[1]])
        else:
            print(0)
    elif query[0]=="2":
        while find(query[1])>=0:
            keys.pop(find(query[1]))
    else:
        L,R=query[1],query[2]
        indL=bisect.bisect_left(keys,L)
        indR=bisect.bisect_right(keys,R)
        for s in keys[indL:indR]:
            print(s,d[s])
