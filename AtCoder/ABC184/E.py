from copy import deepcopy

H,W=[int(i) for i in input().split(" ")]
a=['#'*(W+2)]
for i in range(H):
    a.append(['#']+[j for j in input()]+['#'])
a.append('#'*(W+2))

H+=2
W+=2

teleport={}

for h in range(H):
    for w in range(W):
        tmp=teleport.get(a[h][w],[])
        tmp.append((h,w))
        teleport[a[h][w]]=tmp

s=teleport['S'][0]
d=teleport['G'][0]


G={}
for h in range(H):
    for w in range(W):
        if a[h][w]=='#':
            continue

        tmp=[]
        if a[h-1][w]!='#':
            tmp.append((h-1,w))
        if a[h+1][w]!='#':
            tmp.append((h+1,w))
        if a[h][w-1]!='#':
            tmp.append((h,w-1))
        if a[h][w+1]!='#':
            tmp.append((h,w+1))

        if ord('a')<=ord(a[h][w]) and ord(a[h][w])<=ord('z'):
            tmp+=teleport[a[h][w]]
        G[(h,w)]=tmp

dist=[[10**10 for i in range(W)] for j in range(H)]
dist[s[0]][s[1]]=0


nexts=[s]

while len(nexts)>0:
    _nexts=[]
    for next in nexts:
        neighbors=G[next]
        dist_now=dist[next[0]][next[1]]
        for n in neighbors:
            if dist[n[0]][n[1]]>dist_now+1:
                dist[n[0]][n[1]]=dist_now+1
                _nexts.append(n)
    nexts=deepcopy(_nexts)



if dist[d[0]][d[1]]==10**10:
    print(-1)
else:
    print(dist[d[0]][d[1]])
