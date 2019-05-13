#import numpy as np
#import matplotlib.pyplot as plt
def sumdigits(n):
    result=0
    while n!=0:
        result+=n%10
        n=int(n/10)
    return result

def sunuke(n):
    return n/sumdigits(n)
#sunuke=np.vectorize(sunuke)
"""
deg=14
_s=np.arange(10**deg,+10**(deg+1),1,dtype="float16")
s=sunuke(_s)
"""


deg=0
K=int(input())
count=0
while count<=K:
    i=0
    n=10**(deg+1)-1
    res=[n]
    while n>=10**deg and n>1:
        if n-10**i>0 and sunuke(res[-1])>=sunuke(n-10**i):
            res.append(n-10**i)
            n-=10**i
        else:
            i+=1
    print(res)
    count+=len(res)
    deg+=1
