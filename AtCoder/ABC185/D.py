import sys

def gcd(a,b):
    if min(a,b)==0:
        return max(a,b)
    return gcd(min(a,b),max(a,b)%min(a,b))

N,M=[int(i) for i in input().split(" ")]
if M==0:
    A=[]
else:
    A=[int(i)-1 for i in input().split()]

A=sorted(A)

A=[-1]+A
A=A+[N]

width=[]
for i in range(len(A)-1):
    delta=A[i+1]-A[i]-1
    if delta!=0:
        width.append(delta)
#width=list(set(width))
if len(width)==0:
    print(0)
    sys.exit()

k=min(width)

count = 0
for w in width:
    if w%k==0:
        count+=w//k
    else:
        count+=w//k+1
print(count)
