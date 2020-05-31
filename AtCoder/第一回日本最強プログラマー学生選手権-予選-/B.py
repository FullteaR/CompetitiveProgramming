N,K=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]


inside=0
for i in range(N):
    for j in range(i,N):
        if A[i]>A[j]:
            inside+=1

outside=0
for i in range(N):
    for j in range(N):
        if A[i]>A[j]:
            outside+=1

s=inside*K+outside*((K*(K-1))//2)

print(s%(10**9+7))
