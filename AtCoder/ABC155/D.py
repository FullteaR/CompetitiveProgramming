import itertools
import heapq

N,K=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]
plus=[]
minus=[]
zeros=0
for a in A:
    if a>0:
        plus.append(a)
    elif a==0:
        zeros+=1
    else:
        minus.append(a)

q=[]
heapq.heapify(q)

if len(minus)*len(plus)>=K:
    minus=sorted(minus,reverse=True)[:max(K,2)]
    plus=sorted(plus)[:max(K,2)]
    for m in minus:
        for p in plus:
            heapq.heappush(q,m*p)
    for i in range(K):
        a=heapq.heappop(q)
    print(a)
else:
    K-=len(minus)*len(plus)
    zeros=zeros*(len(minus)+len(plus))+zeros*(zeros-1)//2
    if K<=zeros:
        print(0)
    else:
        K-=zeros
        minus=sorted(minus,reverse=True)[:max(K,2)]
        plus=sorted(plus)[:max(K,2)]
        for i in itertools.combinations(minus,2):
            heapq.heappush(q,i[0]*i[1])
        for i in itertools.combinations(plus,2):
            heapq.heappush(q,i[0]*i[1])
        for i in range(K):
            a=heapq.heappop(q)

        print(a)
