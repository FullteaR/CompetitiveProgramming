p=[False for i in range(200010)]

N=int(input())
pi=[int(i) for i in input().split(" ")]

minimum=0
for i in range(N):
    p[pi[i]]=True
    while p[minimum]:
        minimum+=1
    print(minimum)
