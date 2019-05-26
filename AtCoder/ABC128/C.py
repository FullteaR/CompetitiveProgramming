import numpy as np
import itertools
N,M=[int(i) for i in input().split(" ")]
k_dict={}
for i in range(M):
    _in=[int(j)-1 for j in input().split(" ")]
    k=_in[0]
    s=_in[1::]
    k_dict[i]=s



p=np.asarray([int(i) for i in input().split(" ")])

def _switch(pattern):
    lamps=np.zeros(M)
    for i,pat in enumerate(pattern):
        if pat==0:
            continue
        for key in k_dict:
            if i in k_dict[key]:
                lamps[key]+=1



    return np.sum(lamps%2 == p)==M


retval=0
for i in itertools.product([0,1], repeat=N):
    retval+=_switch(i)
print(retval)
