import bisect
from copy import copy
from collections import Counter



N,M=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]

start=set(A[:M])

include = []
not_include = []
for i in range(N+10):
    if i in start:
        include.append(i)
    else:
        not_include.append(i)

d=dict(Counter(A[:M]))
retval=not_include[0]

for i in range(N-M):
    if A[i]==A[i+M]:
        continue
    assert d[A[i]]>0
    d[A[i]]-=1
    if d[A[i]]==0:
        index = bisect.bisect_left(include,A[i])
        assert include[index]==A[i]
        include.pop(index)
        bisect.insort(not_include,A[i])
    d[A[i+M]]=d.get(A[i+M],0)+1
    if d[A[i+M]]==1:
        index = bisect.bisect_left(not_include,A[i+M])
        assert not_include[index]==A[i+M]
        not_include.pop(index)
        bisect.insort(include,A[i+M])
    retval=min(retval,not_include[0])
print(retval)
