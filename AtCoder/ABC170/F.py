import sys

INF=10000000010

H,W,K=[int(i) for i in input().split(" ")]
x1,y1,x2,y2=[int(i)-1 for i in input().split(" ")]
pond=[]
dist=[]
for i in range(H):
    l=[j=="." for j in input()]
    ld=[INF for j in range(W)]
    pond.append(l)
    dist.append(ld)

D={}
for h in range(H):
    D[h]={}
    for w in range(W):
        tmp=[]
        for d in range(1,K+1):
            if h+d>=H or pond[h+d][w]==False:
                break
            tmp.append((h+d,w))
        for d in range(1,K+1):
            if h-d<0 or pond[h-d][w]==False:
                break
            tmp.append((h-d,w))
        for d in range(1,K+1):
            if w+d>=W or pond[h][w+d]==False:
                break
            tmp.append((h,w+d))
        for d in range(1,K+1):
            if w-d<0 or pond[h][w-d]==False:
                break
            tmp.append((h,w-d))
        D[h][w]=tmp

dist[x1][y1]=0
