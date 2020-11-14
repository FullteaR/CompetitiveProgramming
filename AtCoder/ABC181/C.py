import itertools


def check(p1,p2,p3):
    return (p2[1]-p1[1])*(p3[0]-p1[0])==(p3[1]-p1[1])*(p2[0]-p1[0])


N=int(input())
points=[]
for i in range(N):
    x,y=[int(j) for j in input().split(" ")]
    points.append((x,y))

for iter in itertools.combinations(points,3):
    if check(*iter):
        print("Yes")
        break

else:
    print("No")
