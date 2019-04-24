N,M,C=[int(i) for i in input().split(" ")]
B=[int(i) for i in input().split(" ")]

def ac(A):
    s=0
    for a,b in zip(A,B):
        s+=a*b
    return s+C>0

retval=0
for i in range(N):
    A=[int(i) for i in input().split(" ")]
    retval+=ac(A)

print(retval)
