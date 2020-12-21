H,W,M=[int(i) for i in input().split(" ")]

rocks=[]
for i in range(M):
    rocks.append([int(j)-1 for j in input().split(" ")])

DR = [W for i in range(H)]
RD = [H for i in range(W)]

for r in rocks:
    X,Y=r
    DR[X]=min(DR[X],Y)
    RD[Y]=min(RD[Y],X)

Xs=set([r[0] for r in rocks])
Ys=set([r[1] for r in rocks])
print(DR)
print(RD)
print(Xs,Ys)
bothnot=len(Xs)*len(Ys)
goDR=0
for dr in DR:
    if dr==0:
        break
    goDR+=dr
goRD=0
for rd in RD:
    if rd==0:
        break
    goRD+=rd
notDR=H*W-goDR
notRD=H*W-goRD
notgo=notDR+notRD-bothnot
print(H*W-notgo)
