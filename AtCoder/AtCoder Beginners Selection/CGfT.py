N=int(input())
a=[int(i) for i in input().split(" ")]

a=sorted(a)
a.reverse()

result=0
for i in range(N):
    result+=a[i]*(-1)**i

print(result)
