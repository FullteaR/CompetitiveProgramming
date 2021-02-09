N,X=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]
A=[str(a) for a in A if a!=X]
print(" ".join(A))
