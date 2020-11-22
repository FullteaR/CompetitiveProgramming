from functools import lru_cache
import numpy as np

A0,B0,C0=[int(i) for i in input().split(" ")]

#table=[[[[0 for i in range(310)] for j in range(100)] for k in range(100)] for l in range(100)]
table=np.zeros((110,110,110), dtype=np.float64)
#table[a][b][c][n]=n回金貨をとりだしてa,b,cになる確率

table[A0][B0][C0]Z=1

for a in range(A0,101):
    for b in range(B0,101):
        for c in range(C0,101):
            table[a][b][c]=0
            if a>0:
                table[a][b][c]+=(a-1)*table[a-1][b][c]/(a+b+c-1)
            if b>0:
                table[a][b][c]+=(b-1)*table[a][b-1][c]/(a+b+c-1)
            if c>0:
                table[a][b][c]+=(c-1)*table[a][b][c-1]/(a+b+c-1)
