import copy
import sys
N,K=[int(i) for i in input().split(" ")]
p=[int(i) for i in input().split(" ")]
q=[int(i) for i in input().split(" ")]

p_origin=copy.copy(p)
q_origin=copy.copy(q)

def f(p,q):
    retval=[0 for i in range(N)]
    for _p,_q in zip(p,q):
        retval[_p-1]=_q
    return retval

if K==1:
    print(" ".join([str(i) for i in p]))
    sys.exit()
if K==2:
    print(" ".join([str(i) for i in q]))
    sys.exit()

loop=0

for i in range(K-2):
    tmp=f(p,q)
    p=q
    q=tmp
    if p==p_origin and q==q_origin:
        loop=i+1
        break

if loop==0:
    print(" ".join([str(i) for i in q]))


else:
    p=p_origin
    q=q_origin


    for i in range(K%loop-2+loop):
        tmp=f(p,q)
        p=q
        q=tmp
    print(" ".join([str(i) for i in q]))

print(loop)
