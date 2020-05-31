N=int(input())
A=[]
B=[]
for i in range(N):
    _A,_B=[int(i) for i in input().split(" ")]
    A.append(_A)
    B.append(_B)

A=sorted(A)
B=sorted(B)
if N%2==1:
    print(B[(N+1)//2-1]-A[(N+1)//2-1]+1)

else:
    print(B[N//2-1]-A[N//2-1]+B[N//2]-A[N//2]+1)
