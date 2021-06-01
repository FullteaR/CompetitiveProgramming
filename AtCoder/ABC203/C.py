import sys
N,K=[int(i) for i in input().split(" ")]

friends={}
for i in range(N):
    A,B=[int(j) for j in input().split(" ")]
    friends[A] = friends.get(A,0)+B

friends = sorted(friends.items(), key=lambda w:w[0])

pos = 0
for next in friends:
    if next[0]-pos<=K:
        K-=(next[0]-pos)
        pos = next[0]
        K+=next[1]
    else:
        print(pos+K)
        sys.exit(0)

print(pos+K)
