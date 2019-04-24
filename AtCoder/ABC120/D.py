import numpy as np
N,M=[int(i) for i in input().split(" ")]
A=[]
B=[]
for i in range(M):
    a,b=[int(i)-1 for i in input().split(" ")]
    A.append(a)
    B.append(b)

A.reverse()
B.reverse()
retval=[]
concat={}

def whatgroup(a):
    n=a
    while n in concat:
        n=concat[n]
    return n

island=[i for i in range(N)]
