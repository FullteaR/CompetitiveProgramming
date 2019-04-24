N=int(input())
A=int(input())
B=int(input())
C=int(input())
D=int(input())
E=int(input())




minimum=min(A,B,C,D,E)
if minimum>=N:
    print(5)
else:
    if N%minimum==0:
        print(N//minimum+4)
    else:
        print(N//minimum +5)
