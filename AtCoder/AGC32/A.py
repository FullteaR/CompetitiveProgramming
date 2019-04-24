import random
import sys
import copy
N=int(input())
b=[int(i) for i in input().split(" ")]

def step(a,c):
    return a[:c-1:]+[c]+a[c-1::]

def create_a(command):
    a=[]
    for c in command:
        if len(a)+1<c:
            return False
        a=step(a,c)
    return a


def creatable(b):
    if b==[1]:
        return True,[1]
    if len(b)==1:
        return False,[1]

    judge=False
    history=[]
    for i in range(len(b)):
        if b[i]==i+1:
            judge,history=creatable(b[:i:]+b[i+1::])
            if judge:
                history.append(i+1)
        else:
            continue
        if judge:
            break
    return judge,history



#judge,history=creatable(b)

for i in range(100000):
    _b=copy.copy(b)
    random.shuffle(_b)
    if create_a(_b)==b:
        for c in _b:
            print(c)
        sys.exit()
print(-1)
