import sys
from functools import lru_cache

d={}

N=int(input())

for i in range(1,N+1):
    start=int(str(i)[0])
    end=int(str(i)[-1])
    tmp=d.get((start,end),0)
    d[(start,end)]=tmp+1

retval=0

for i in range(1,10):
    for j in range(1,10):
        retval+=d.get((i,j),0)*d.get((j,i),0)

print(retval)
