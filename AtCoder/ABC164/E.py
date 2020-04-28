INF=10**10+10

def minCost(history):
    totalCost=0
    for i in range(len(history)-1):
        totalCost+=costs[(history[i],history[i+1])][0]

    table=[[0 for i in range(totalCost+1)] for j in len(history)]

    cs=[kakin[h][0] for h in history]
    ds=[kakin[h][1] for h in history]

    for i in range(totalCost+1):
        table[0][i]=(cs[0]//i)*ds[0]

    for j in range(1,len(history)):
        table[j][i]=table[j-1][i]
        if i>=cs[j]:
            table[j][i]=min(table[j][i], table[j-1][i-cs[j]]+ds[j])

    return table[-1][-1]


N,M,S=[int(i) for i in input().split(" ")]

costs={}

for i in range(M):
    U,V,A,B=[int(j) for j in input().split(" ")]
    U-=1
    V-=1
    costs[(U,V)]=(A,B)
    costs[(V,U)]=(A,B)

kankin=[]
for i in range(N):
    C,D=[int(j) for j in input().split(" ")]
    kankin.append((C,D))

def route(i,already):
    if i==0:
        return [[0]]

    already.append(i)
    routs=[]

    for v in range(N):
        if ((i,v) in costs)==False:
            continue
        if v in already:
            continue
        routs+=route(v,already)

    return [r+[i] for r in routs]

for i in range(N):
    routes=route(i,already=[])
    retval=0
    for r in routes:
        for i in range(1,len(r)+1):
            max(retval,minCost(r[:i]))
    print(retval)
