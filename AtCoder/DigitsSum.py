def sumdigits(n):
    result=0
    while n!=0:
        result+=n%10
        n=int(n/10)
    return result

N=int(input())

result=10**10
for i in range(1,int(N/2)+1):
    result=min(sumdigits(i)+sumdigits(N-i),result)


print(result)
