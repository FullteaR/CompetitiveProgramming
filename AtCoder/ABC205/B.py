N=int(input())
A=set([int(i) for i in input().split(" ")])

if A==set([i+1 for i in range(N)]):
    print("Yes")
else:
    print("No")