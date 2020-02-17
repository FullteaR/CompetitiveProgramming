from collections import Counter

N=int(input())
S=[]
for i in range(N):
    S.append(input())

c=Counter(S)
c=sorted(dict(c).items(),key=lambda w:(-w[1],w[0]))

for w in c:
    if w[1]==c[0][1]:
        print(w[0])
