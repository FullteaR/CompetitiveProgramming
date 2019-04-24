N=int(input())
A1=[int(i) for i in input().split(" ")]
A2=[int(i) for i in input().split(" ")]

total=sum(A2)+A1[0]
maximum=total
for i in range(N-1):
    total+=A1[i+1]
    total-=A2[i]
    maximum=max(maximum,total)
print(maximum)
