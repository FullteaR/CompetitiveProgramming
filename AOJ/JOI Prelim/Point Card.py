N,M=[int(i) for i in input().split(" ")]

cards=[]
for i in range(M):
    A,B=[int(j) for j in input().split(" ")]
    cards.append((A,B))

cards=sorted(cards)
retval=0
for c in cards[1::]:
    if c[0]<N:
        retval+=N-c[0]
print(retval)
