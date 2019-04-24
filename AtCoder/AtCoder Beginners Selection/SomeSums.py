def sumdigits(n):
    result=0
    while n!=0:
        result+=n%10
        n=int(n/10)
    return result

N,A,B=(int(i) for i in input().split(" "))
result=0
for i in range(1,N+1):
    s=sumdigits(i)
    if s>=A and s<=B:
        result+=i

print(result)
