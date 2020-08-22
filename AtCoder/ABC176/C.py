N=int(input())
A=[int(i) for i in input().split(" ")]

maximum=A[0]
dai=0
for a in A:
    if a<maximum:
        dai+=maximum-a
    if a>maximum:
        maximum=a

print(dai)
