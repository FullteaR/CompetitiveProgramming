import sys
K,A,B=[int(i) for i in input().split(" ")]


if A>=K+1:
    print(K+1)


elif B>A+2:
    K-=(A-1)
    biscuit=A
    biscuit+=(B-A)*(int(K/2))
    if K%2==1:
        biscuit+=1
    print(biscuit)

else:
    print(K+1)
