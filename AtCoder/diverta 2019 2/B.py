import itertools
from collections import Counter
import sys
N=int(input())
balls=[]

for i in range(N):
    x,y=[int(j) for j in input().split(" ")]
    balls.append((x,y))

pqs=[]
if N==1:
    print(1)
    sys.exit()
for i in itertools.permutations(balls,2):
    p=i[1][0]-i[0][0]
    q=i[1][1]-i[0][1]
    pqs.append((p,q))

c=Counter(pqs)
c=dict(c)
c=sorted(c.items(),key=lambda w:w[1],reverse=True)
print(N-c[0][1])
