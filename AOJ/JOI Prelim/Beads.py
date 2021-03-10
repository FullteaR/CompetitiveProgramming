import sys
from functools import lru_cache
sys.setrecursionlimit(22000)

def fact(n):
    if n==0:
        return 1
    return n*fact(n-1)


@lru_cache()
def solve(n,r):
    return fact(n+r-1)//(fact(n-1)*fact(r))

n,m,r=[int(i) for i in input().split(" ")]
r-=n*m
if r<0:
    print(0)
    sys.exit()
print(solve(n,r))
