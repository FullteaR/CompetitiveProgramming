import itertools

N,M = [int(i) for i in input().split(" ")]
retvals = []
for iter in itertools.combinations([i+1 for i in range(M)], N):
    iter = sorted(iter)
    retvals.append(tuple(iter))

for r in retvals:
    print(" ".join([str(j) for j in r]))