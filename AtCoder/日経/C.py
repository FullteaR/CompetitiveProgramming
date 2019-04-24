N=int(input())
dinner=[]
for i in range(N):
    a,b=[int(j) for j in input().split(" ")]
    dinner.append([a,b])

dinner=sorted(dinner,key=lambda x:x[1]+x[0])
takahashi=0
aoki=0

while True:
    d=dinner.pop(-1)
    takahashi+=d[0]
    if len(dinner)==0:
        break
    d=dinner.pop(-1)
    aoki+=d[1]
    if len(dinner)==0:
        break

print(takahashi-aoki)
