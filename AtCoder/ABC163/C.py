N=int(input())
A=[0 for i in range(N)]
a=[int(i) for i in input().split(" ")]
for _a in a:
    A[_a-1]+=1

for a in A:
    print(a)
