from functools import lru_cache



S=input()
count=[0 for i in range(2019)]
length=len(S)
#S=int(S)
S=S+'0'
S=S[::-1]
_S=0

base=1
for i,s in enumerate(S):
    _S=base*int(s)+_S
    count[_S%2019]+=1
    base*=10
    base=base%2019
    _S=_S%2019



retval=0
for key in range(2019):
    retval+=count[key]*(count[key]-1)//2


print(retval)
