from functools import lru_cache
import numpy as np

N,K=[int(i) for i in input().split(" ")]
V=[int(i) for i in input().split(" ")]

retval=0
for left in range(max(N+1,K+1)):
    for right in range(min(N-left+1,K-left+1)):
        modoseru=K-(left+right)
        temoto=np.asarray(sorted(V[:left:]+V[N-right::]))
        modosu=min(np.sum(temoto<0),modoseru)
        retval=max(sum(temoto[modosu::]),retval)

print(retval)
