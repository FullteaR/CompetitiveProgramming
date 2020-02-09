import itertools

N,M=[int(i) for i in input().split(" ")]

people=[[0 for i in range(N)] for j in range(N)]
for _ in range(M):
    x,y=[int(i) for i in input().split(" ")]
    x-=1
    y-=1
    people[x][y]=1
    people[y][x]=1

retval=0
for i in itertools.product([0,1],repeat=N):
    flag=True
    for j in itertools.combinations([k for k in range(N)],2):
        if i[j[0]]==0 or i[j[1]]==0:
            continue
        if people[j[0]][j[1]]==0:
            flag=False
    if flag:
        retval=max(retval,sum(i))

print(retval)
