import bisect

S=[]

q=int(input())

def find(x):
    index=bisect.bisect_left(S,x)
    if index==len(S):
        return False
    return S[index]==x


for _ in range(q):
    query=[int(i) for i in input().split(" ")]
    if query[0]==0:
        if find(query[1]):
            pass
        else:
            bisect.insort_left(S, query[1])
        print(len(S))
    elif query[0]==1:
        if find(query[1]):
            print(1)
        else:
            print(0)
    elif query[0]==2:
        if find(query[1]):
            S.remove(query[1])
    else:
        L,R=query[1],query[2]
        indL=bisect.bisect_left(S,L)
        indR=bisect.bisect_right(S,R)
        for s in S[indL:indR]:
            print(s)
