
N,K=[int(i) for i in input().split(" ")]
sunuke=[0 for i in range(N)]
for i in range(K):
    d=int(input())
    A=[int(j) for j in input().split(" ")]
    for a in A:
        sunuke[a-1]+=1

retval=0
for s in sunuke:
    if s==0:
        retval+=1
print(retval)
