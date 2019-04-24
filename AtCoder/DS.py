def sumdigits(n):
    result=0
    while n!=0:
        result+=n%10
        n=int(n/10)
    return result

N=int(input())
if N%sumdigits(N)==0:
    print("Yes")
else:
    print("No")
