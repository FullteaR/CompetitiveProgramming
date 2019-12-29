#TLE 対応考え中...

n,q=[int(i) for i in input().split(" ")]

L=[[] for i in range(n)]

for _ in range(q):
    query=[int(j) for j in input().split(" ")]
    if query[0]==0:
        L[query[1]].append(query[2])
    elif query[0]==1:
        print(" ".join([str(i) for i in L[query[1]]]))
    else:
        L[query[2]]+=L[query[1]]
        L[query[1]]=[]
