N,u,v=[int(i) for i in input().split(" ")]
u-=1
v-=1
graph={}
for i in range(N-1):
    A,B=[int(j) for j in input().split(" ")]
    if A-1 in graph:
        d=graph[A-1]
        d.append(B-1)
        graph[A-1]=d
    else:
        graph[A-1]=[B-1]
    if B-1 in graph:
        d=graph[B-1]
        d.append(A-1)
        graph[B-1]=d
    else:
        graph[B-1]=[A-1]

dist_takahashi=[-1 for i in range(N)]
dist_takahashi[u]=0
next=[u]
d=1
while -1 in dist_takahashi:
    _next=[]
    for n in next:
        nodes=graph[n]
        for i in nodes:
            if dist_takahashi[i]==-1:
                _next.append(i)
    for n in _next:
        dist_takahashi[n]=d
    next=_next
    d+=1

dist_aoki=[-1 for i in range(N)]
dist_aoki[v]=0
next=[v]
d=1
while -1 in dist_aoki:
    _next=[]
    for n in next:
        nodes=graph[n]
        for i in nodes:
            if dist_aoki[i]==-1:
                _next.append(i)
    for n in _next:
        dist_aoki[n]=d
    next=_next
    d+=1


retval=0

for i in range(N):
    if dist_aoki[i]<dist_takahashi[i]:
        continue

    retval=max(retval,dist_aoki[i]-1)


print(retval)
