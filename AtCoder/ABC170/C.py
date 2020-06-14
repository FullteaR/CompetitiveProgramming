import sys

X,N=[int(i) for i in input().split(" ")]
if N==0:
    print(X)
    sys.exit(0)
p=[int(i) for i in input().split(" ")]

i=0
while True:
    if (X-i in p)==False:
        print(X-i)
        sys.exit(0)
    elif (X+i in p)==False:
        print(X+i)
        sys.exit(0)
    else:
        i+=1
