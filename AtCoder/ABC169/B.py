import sys
N=int(input())
A=[int(i) for i in input().split(" ")]
if 0 in A:
    print(0)
    sys.exit(0)
A=sorted(A,reverse=True)
mul=1
for a in A:
    mul*=a

    if mul>10**18:
        print(-1)
        sys.exit(0)

print(mul)
