N,W=[int(i) for i in input().split(" ")]
cheeses = []
for i in range(N):
    A,B = [int(j) for j in input().split(" ")]
    cheeses.append((A,B))

cheeses = sorted(cheeses, key = lambda w : w[0], reverse=True)

retval = 0
for c in cheeses:
    if W<=0:
        break
    if c[1]<=W:
        retval += c[0]*c[1]
        W-=c[1]
    else:
        retval+=c[0]*W
        W=0
print(retval)