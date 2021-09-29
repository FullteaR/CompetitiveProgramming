def calcHeight(d,h,D,H):
    return h - d*(H-h)/(D-d)

N,D,H = [int(i) for i in input().split(" ")]

retval = 0
for i in range(N):
    d, h = [int(j) for j in input().split(" ")]
    retval = max(retval, calcHeight(d,h,D,H))
print(retval)