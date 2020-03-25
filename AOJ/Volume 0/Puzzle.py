from collections import Counter
from copy import copy

def _check(pi):
    pi=sorted(pi)
    if len(pi)==0:
        return True
    retval=False
    try:
        _pi=copy(pi)
        tmp=_pi[0]
        for i in range(3):
            _pi.remove(tmp)
        retval = retval or _check(_pi)
    except:
        pass

    try:
        _pi=copy(pi)
        tmp=_pi[0]
        for i in range(3):
            _pi.remove(tmp+i)
        retval = retval or _check(_pi)
    except:
        pass

    return retval

def check(pi,tsumo):
    pi=pi+[tsumo]
    c=Counter(pi)
    for i in range(1,10):
        if c[i]>4:
            return False

    for i in range(1,10):
        if c[i]>=2:
            _pi = copy(pi)
            _pi.remove(i)
            _pi.remove(i)
            _pi=sorted(_pi)
            if _check(_pi):
                return True
    return False


while True:
    try:
        s=input()
        s=[int(i) for i in s]
        retval=[]
        for i in range(1,10):
            if check(s,i):
                retval.append(str(i))
        if len(retval)==0:
            print("0")
        else:
            print(" ".join(retval))
    except EOFError:
        break
