import sys
A,B,C=[int(i) for i in input().split(" ")]

if C==0:
    while True:
        if A>0:
            A-=1
        else:
            print("Aoki")
            sys.exit()
        if B>0:
            B-=1
        else:
            print("Takahashi")
            sys.exit()

else:
    while True:
        if B>0:
            B-=1
        else:
            print("Takahashi")
            sys.exit()
        if A>0:
            A-=1
        else:
            print("Aoki")
            sys.exit()
