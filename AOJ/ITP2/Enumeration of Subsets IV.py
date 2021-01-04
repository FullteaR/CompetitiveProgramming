import itertools

n,k=[int(i) for i in input().split(" ")]

d={}

for iter in itertools.combinations([i for i in range(n)],k):
    M=0;
    for i in iter:
        M+=2**i
    d[M]="{0}: ".format(M)+" ".join([str(i) for i in sorted(list(iter))])

for i in sorted(d.items()):
    print(i[1])
