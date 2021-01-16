mod = 998244353
inv_3 = pow(3,-1,mod)
from collections import Counter

H,W,K=[int(i) for i in input().split(" ")]
grid = [['N' for w in range(W+2)]]
for h in range(H):
    grid.append(['N']+['B' for w in range(W)]+['N'])
grid.append(['N' for w in range(W+2)])

H+=2
W+=2

roots = [[0 for w in range(W)] for h in range(H)]


roots[1][1]=pow(3,(H-2)*(W-2)-K,mod)

for i in range(K):
    h,w,c=input().split(" ")
    grid[int(h)][int(w)]=c

for h in range(1,H-1):
    for w in range(1,W-1):
        if grid[h-1][w] in ('D','X'):
            roots[h][w]+=roots[h-1][w]
        elif grid[h-1][w] == 'B':
            roots[h][w]+=roots[h-1][w]*inv_3*2
        if grid[h][w-1] in ('R','X'):
            roots[h][w]+=roots[h][w-1]
        elif grid[h][w-1] == 'B':
            roots[h][w]+=roots[h][w-1]*inv_3*2
        roots[h][w] = roots[h][w]%mod

print(roots[H-2][W-2])
