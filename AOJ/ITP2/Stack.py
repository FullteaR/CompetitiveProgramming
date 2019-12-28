n,q=[int(i) for i in input().split(" ")]
S=[[] for i in range(n)]

for _ in range(q):
    query=[int(i) for i in input().split(" ")]
    if query[0]==0:
        S[query[1]].append(query[2])
    elif query[0]==1:
        if len(S[query[1]])>0:
            print(S[query[1]][-1])
    else:
        if len(S[query[1]])>0:
            S[query[1]].pop(-1)
