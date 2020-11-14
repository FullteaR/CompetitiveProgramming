def _Sum(N):
    return (N*(N+1))//2

def Sum(a,b):
    return _Sum(b)-_Sum(a-1)


N=int(input())
retval=0
for i in range(N):
    A,B=[int(j) for j in input().split(" ")]
    retval+=Sum(A,B)

print(retval)
