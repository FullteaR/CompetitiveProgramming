import math

N,A,B,K=(int(i) for i in input().split(" "))



def combination(r,g,b,w):
    child=math.factorial(r+g+b+w)
    mom=math.factorial(r)*math.factorial(g)*math.factorial(b)*math.factorial(w)
    return int(child/mom)


pqs=[]
for p in range(int(K/A+1)):
    if (K-p*A)%B==0:
        q=int((K-p*A)/B)
        pqs.append((p,q))

rgbs=[]
for pq in pqs:
    r=pq[0]
    b=pq[1]
    g=0
    while r>=0 and b>=0:
        if r+g+b<=N:
            rgbs.append((r,g,b))
        r-=1
        b-=1
        g+=1

result=0
for rgb in rgbs:
    r=rgb[0]
    g=rgb[1]
    b=rgb[2]
    w=N-r-g-b
    result+=combination(r,g,b,w)

print(result%998244353)
