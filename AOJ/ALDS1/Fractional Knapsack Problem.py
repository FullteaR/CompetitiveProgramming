N,W=[int(i) for i in input().split(" ")]

items=[]
for i in range(N):
    v,w=[int(j) for j in input().split(" ")]
    items.append((v,w))

items=sorted(items,key=lambda w: w[0]/w[1], reverse=True)

val=0
for item in items:
    v,w=item
    if W>=w:
        W-=w
        val+=v
    else:
        val+=v*W/w
        W=0

print(val)
