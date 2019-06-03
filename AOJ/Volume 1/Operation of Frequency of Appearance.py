import sys


def _nextstep(s):
    retval=[0 for i in range(len(s))]
    for i,si in enumerate(s):
        retval[i]=s.count(si)
    return retval

def fudouten(s):
    count=0
    while True:
        next=_nextstep(s)
        if next==s:
            return count,s
        else:
            s=next
            count+=1

while True:
    n=int(input())
    if n==0:
        sys.exit()
    s=[int(i) for i in input().split(" ")]
    count,ans=fudouten(s)
    print(count)
    print(" ".join([str(s) for s in ans]))
