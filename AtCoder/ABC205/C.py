A,B,C=[int(i) for i in input().split(" ")]

if C==0:
    print("=")

elif C%2==0 or (A>=0 and B>=0):
    A=abs(A)
    B=abs(B)
    if A<B:
        print("<")
    elif A>B:
        print(">")
    else:
        print("=")

else:
    if A<B:
        print("<")
    elif A>B:
        print(">")
    else:
        print("=")
    