import sys
A=int(input())
S=input()

if A==0:
    print("Yes")
    sys.exit()

for s in S:
    if s=="+":
        A+=1
    else:
        A-=1
    if A==0:
        print("Yes")
        sys.exit()

print("No")
