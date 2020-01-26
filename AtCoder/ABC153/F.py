import sys
N,D,A=[int(i) for i in input().split(" ")]
enemies=[]
for i in range(N):
    X,H=[int(j) for j in input().split(" ")]
    enemies.append([X,H])

enemies=sorted(enemies,key=lambda w:w[0])

if enemies[-1][0]-enemies[0][0]<=2*D:
    hpmax=sorted(enemies,key=lambda  w:w[1])[-1][1]
    if hpmax%A==0:
        print(hpmax//A)
    else:
        print(hpmax//A+1)
    sys.exit()


retval=0
for i in range(N):
    hp=enemies[i][1]
    place=enemies[i][0]
    if hp<=0:
        continue
    if hp%A==0:
        bomb=hp//A
    else:
        bomb=hp//A+1
    retval+=bomb

    for j in range(i,N):
        if enemies[j][0]-place>2*D:
            break
        enemies[j][1]-=bomb*A



print(retval)
