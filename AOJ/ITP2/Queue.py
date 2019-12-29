n,q=[int(i) for i in input().split(" ")]

Q=[[] for i in range(n)]

for _ in range(q):
    query=[int(j) for j in input().split(" ")]
    if query[0]==0:
        Q[query[1]].append(query[2])
    elif query[0]==1:
        if len(Q[query[1]])>0:
            print(Q[query[1]][0])
    else:
        if len(Q[query[1]])>0:
            Q[query[1]].pop(0)
