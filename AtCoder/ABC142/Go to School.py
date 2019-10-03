N=int(input())
A=[int(i) for i in input().split(" ")]
d={}
for i,a in enumerate(A):
    d[a]=i+1

retval=[str(d[i+1]) for i in range(N)]
print(" ".join(retval))
