import heapq
X,Y,Z,K=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]
B=[int(i) for i in input().split(" ")]
C=[int(i) for i in input().split(" ")]

AB=[]
for a in A:
    for b in B:
        AB.append(a+b)

AB=heapq.nlargest(K,AB)
ABC=[]
for ab in AB:
    for c in C:
        ABC.append(ab+c)

for cake in heapq.nlargest(K,ABC):
    print(cake)
