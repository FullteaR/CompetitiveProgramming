N,M=[int(i) for i in input().split(" ")]
stores=[]
for j in range(N):
    A,B=[int(i) for i in input().split(" ")]
    stores.append([A,B])

stores=sorted(stores,key=lambda w:w[0])

money=0

while M>0:
    store=stores.pop(0)
    if store[1]>=M:
        money+=store[0]*M
        M=0
    else:
        money+=store[1]*store[0]
        M-=store[1]
print(money)
