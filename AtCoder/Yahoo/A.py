import sys
N,K=[int(i) for i in input().split(" ")]

if N%2==1:
    if int(N/2)+1>=K:
            print("YES")
    else:
            print("NO")
else:
        if int(N/2)>=K:
                print("YES")
        else:
                print("NO")
