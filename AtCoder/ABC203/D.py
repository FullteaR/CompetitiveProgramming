import numpy as np
import bisect
from tqdm.auto import tqdm

N,K=[int(i) for i in input().split(" ")]

A = []
for i in range(N):
    A.append([int(j) for j in input().split(" ")])


retval=10**10

if K%2==1:
    ind = K*K//2
else:
    ind =K*K//2-1



for i in tqdm(range(N-K+1)):
    pond = []
    for k in range(i,K+i):
        for j in range(K):
            pond.append(A[k][j])
    pond = sorted(pond)
    retval = min(retval,pond[ind])
    #print(pond)
    
    for j in range(N-K):
        for k in range(i,K+i):
            bisect.insort(pond, A[k][j+K])
        for k in range(i,K+i):
            index = bisect.bisect_left(pond,A[k][j])
            pond.pop(index)
        #print(pond)
        retval = min(retval,pond[ind])
        


print(retval)