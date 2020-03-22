from collections import Counter

N=int(input())
A=[int(i) for i in input().split(" ")]
c=Counter(A)
c=dict(c)
base=0
for key in c:
    base+=c[key]*(c[key]-1)//2


for a in A:
    _base=base
    ca=c[a]
    if ca>1:
        _base-=ca*(ca-1)//2
        _base+=(ca-1)*(ca-2)//2
    print(_base)
