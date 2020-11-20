import itertools

N,K=[int(i) for i in input().split(" ")]
T=[]
for i in range(N):
    T.append([int(j) for j in input().split(" ")])

retval=0
for iter in itertools.permutations([i for i in range(1,N)]):
    root=[0]+list(iter)+[0]
    cost=0
    for i in range(N):
        cost+=T[root[i]][root[i+1]]
    if cost==K:
        retval+=1

print(retval)
