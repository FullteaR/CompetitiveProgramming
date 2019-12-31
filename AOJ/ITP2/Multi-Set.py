import bisect

S=[]

q=int(input())

def find(x):
    index=bisect.bisect_left(S,x)
    if index==len(S):
        return -1
    if S[index]==x:
        return index
    else:
        return -1


for _ in range(q):
    query=[int(i) for i in input().split(" ")]
    if query[0]==0:
        bisect.insort_left(S, query[1])
        print(len(S))
    elif query[0]==1:
        L,R=query[1],query[1]
        indL=bisect.bisect_left(S,L)
        indR=bisect.bisect_right(S,R)
        print(len(S[indL:indR]))
    elif query[0]==2:
        while find(query[1])>=0:
            S.pop(find(query[1]))
    else:
        L,R=query[1],query[2]
        indL=bisect.bisect_left(S,L)
        indR=bisect.bisect_right(S,R)
        for s in S[indL:indR]:
            print(s)
