from functools import lru_cache

def g1(x):
    x = str(x)
    x = sorted(x, reverse=True)
    return int("".join(x))

def g2(x):
    x = str(x)
    x = sorted(x, reverse=False)
    return int("".join(x))

@lru_cache()
def f(x):
    return g1(x)-g2(x)

N,K=[int(i) for i in input().split(" ")]
for i in range(K):
    N=f(N)

print(N)
