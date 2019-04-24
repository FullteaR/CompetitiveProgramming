import sys

N=int(input())

A=[int(i) for i in input().split(" ")]

result=0
while True:
    for i in range(N):
        if A[i]%2==0:
            A[i]=A[i]/2
        else:
            print(result)
            sys.exit()
    result+=1
