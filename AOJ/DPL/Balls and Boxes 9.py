from functools import lru_cache
import sys

mod=1000000007

n,k=[int(i) for i in input().split(" ")]



facts=[1 for i in range(n+k+1)]

for i in range(1,n+k+1):
    facts[i]=i*facts[i-1]

if n<k:
    print(0)
    sys.exit()

tables=[[-1 for i in range(k+1)] for j in range(n+1)]

def f(n,k):
    if k==1:
        return 1

    elif n==k:
        return facts[n]

    elif tables[n][k]!=-1:
            return tables[n][k]

    else:
        retval=(k*f(n-1,k)+k*f(n-1,k-1))
        tables[n][k]=retval
        return retval

print((f(n,k)//facts[k])%mod)
