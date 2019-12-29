n=int(input())

pairs=[]

for _ in range(n):
    xy=[int(i) for i in input().split(" ")]
    pairs.append(xy)

pairs=sorted(pairs)

for p in pairs:
    print(p[0],p[1])
