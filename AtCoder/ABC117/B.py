N=int(input())
L=[int(i) for i in input().split(" ")]
L=sorted(L)
if L[-1]<sum(L[:N-1:]):
    print("Yes")
else:
    print("No")
