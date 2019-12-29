A,B,K=[int(i) for i in input().split(" ")]

if(A>=K):
    A-=K
else:
    B-=(K-A)
    A=0
    if(B<0):
        B=0

print(A,B)
