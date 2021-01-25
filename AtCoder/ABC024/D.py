A=int(input())
B=int(input())
C=int(input())

mod=1000000007


r=(A*(B-A)+(B-A)*(C-A))*pow(A*A-(A-B)*(A-C),-1,mod)
r=r%mod
c=((C-A)*(B-A)+A*(C-A))*pow(A*A-(A-B)*(A-C),-1,mod)
c=c%mod

print(r,c)
