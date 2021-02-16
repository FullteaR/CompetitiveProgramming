N = int(input())
berries = {}
for i in range(N):
    A, T = [int(j) for j in input().split(" ")]
    berries[A] = max(berries.get(A, 0), T)

berries = sorted(berries.items(), key=lambda w: w[0])
length = berries[-1][0]
waits = max([i[1] - (2 * length - i[0]) for i in berries] + [0])
print(2 * length + waits)
