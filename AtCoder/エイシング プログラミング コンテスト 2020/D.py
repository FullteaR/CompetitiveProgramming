from functools import lru_cache
from collections import Counter


@lru_cache(maxsize=4*(10**5))
def _f(n):
    string=bin(n)
    popcount=string.count('1')
    return n%popcount

@lru_cache(maxsize=4*(10**5))
def f(n):
    if n==0:
        return 0
    else:
        return 1+f(_f(n))

cache=[f(i) for i in range(2*(10**5)+10)]


N=int(input())
X=[i for i in input()]

pc=0
for x in X:
    if x=='1':
        pc+=1

first=[]

for i in range(N):
    if X[i]=='1':
        X[i]='0'
        pc-=1
    else:
        X[i]='1'
        pc+=1

    if pc==0:
        first.append(0)
    else:
        first.append(int("".join(X), 2)%pc)


    if X[i]=='1':
        X[i]='0'
        pc-=1
    else:
        X[i]='1'
        pc+=1


for f in first:
    print(cache[f]+1)
