import copy
import sys
import random

def test(p,q):

    N=len(p)
    K=1000000000000

    p_origin=copy.copy(p)
    q_origin=copy.copy(q)

    def f(p,q):
        retval=[0 for i in range(N)]
        for _p,_q in zip(p,q):
            retval[_p-1]=_q
        return retval



    loop=0

    for i in range(K-2):
        tmp=f(p,q)
        p=q
        q=tmp
        if p==p_origin and q==q_origin:
            loop=i+1
            break

    if loop==0:
        return loop



    else:
        p=p_origin
        q=q_origin


        for i in range(K%loop-2+loop):
            tmp=f(p,q)
            p=q
            q=tmp


    return loop


for i in range(3,15):
    print("-------",i,"----------")
    for j in range(20):
        p=[k+1 for k in range(i)]
        random.shuffle(p)
        q=[k+1 for k in range(i)]
        random.shuffle(q)

        print(test(p,q))
