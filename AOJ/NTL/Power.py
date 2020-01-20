from functools import lru_cache
mod=1000000007

m,n=[int(i) for i in input().split(" ")]

@lru_cache()
def power(m,n,mod):
    if n==0:
        return 1
    elif n==1:
        return m
    elif n%2==0:
        return ((power(m,n//2,mod)%mod) * (power(m,n//2,mod)%mod))%mod
    else:
        return (power(m,n-1,mod)*m)%mod

print(power(m,n,mod))
