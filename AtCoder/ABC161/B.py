N,M=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]

S=sum(A)
for i in sorted(A,reverse=True)[:M]:
    if i<S/(4*M):
        print("No")
        break
else:
    print("Yes")
