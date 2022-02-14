from functools import lru_cache

@lru_cache()
def calc(X):
    MOD = 998244353
    if X<=4:
        return X
    else:
        if X%2==0:
            return pow(calc(X//2),2,MOD)
        else:
            return (calc(X//2)*calc(X//2+1))%MOD

X = int(input())
print(calc(X))

