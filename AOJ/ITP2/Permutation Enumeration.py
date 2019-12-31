import itertools

n=int(input())
for i in itertools.permutations([i+1 for i in range(n)]):
    print(" ".join([str(j) for j in i]))
