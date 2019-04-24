N,M=[int(i) for i in input().split(" ")]
X=[int(i) for i in input().split(" ")]
X=sorted(X)
delta=[abs(X[i+1]-X[i]) for i in range(M-1)]
delta=sorted(delta)
if M>N:
    print(sum(delta[:M-N:]))
else:
    print(0)
