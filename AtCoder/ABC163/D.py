mod=10**9+7

N,K=[int(i) for i in input().split(" ")]

nums=[i for i in range(N+1)]

retval=0
min=sum(nums[:K])
max=sum(nums[-K:])

for k in range(K,N+2):
    min=k*(k-1)//2
    max=N*k-min
    retval+=max-min+1
retval=retval%mod
print(retval)
