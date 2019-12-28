n,q=[int(i) for i in input().split(" ")]
A=[[] for i in range(n)]

for _ in range(q):
    query=[int(i) for i in input().split(" ")]
    if query[0]==0:
        A[query[1]].append(query[2])
    elif query[0]==1:
        print(" ".join([str(j) for j in A[query[1]]]))
    else:
        A[query[1]]=[]
