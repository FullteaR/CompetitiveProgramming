S,T=input().split(" ")
A,B=[int(i) for i in input().split(" ")]
U=input()

if S==U:
    print(A-1,B)
else:
    print(A,B-1)
