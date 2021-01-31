import itertools

N,M=[int(i) for i in input().split(" ")]

conditions=[]
for i in range(M):
    A,B=[int(j) for j in input().split(" ")]
    conditions.append((A,B))
K=int(input())
puts=[]
for i in range(K):
    C,D=[int(j) for j in input().split(" ")]
    puts.append((C,D))

retval=0
for iter in itertools.product(*puts):
    iter = set(iter)
    score=0
    for c in conditions:
        A,B=c
        if A in iter and B in iter:
            score+=1

    retval=max(score, retval)

print(retval)
