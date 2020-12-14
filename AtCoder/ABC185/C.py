from functools import lru_cache
L=int(input())

@lru_cache()
def f(n):
    if n==0:
        return 1
    else:
        return f(n-1)*n

print(f(L-1)//(f(11)*(f(L-12))))
