mod=10**9+7

from functools import lru_cache

@lru_cache()
def pow(N,K):
    if K==0:
        return 1
    elif K==1:
        return N
    if K%2==0:
        return (pow(N,K//2)*pow(N,K//2))%mod
    else:
        return (N*pow(N,K-1))%mod



def f(N,K,i):
    if table[K]>0 and i==1:
        return table[K]

    if K==i:
        return 1
    elif K==1:
        return 1

    if i==1:
        sigma=0
        for j in range(2,K+1):
            sigma+=f(N,K//j,1)
            sigma=sigma%mod
        retval=(pow(K,N)-sigma)%mod
        table[K]=retval
        return retval

    else:
        return f(N,K//i,1)%mod


def calc(N,K):
    retval=0
    for i in range(1,K+1):
        retval+=i*f(N,K,i)
        retval=retval%mod
    return retval

N,K=[int(i) for i in input().split(" ")]

table=[-1 for i in range(K+1)]
table[1]=1


print(calc(N,K))
