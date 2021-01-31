N,S,D=[int(i) for i in input().split(" ")]
spells=[]
for i in range(N):
    spells.append([int(j) for j in input().split(" ")])

success=False
for s in spells:
    X,Y=s
    if X>=S or Y<=D:
        continue
    success=True
    break
if success:
    print("Yes")
else:
    print("No")
