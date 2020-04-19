N,M=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]
s=sum(A)
if N>=s:
    print(N-s)
else:
    print(-1)
