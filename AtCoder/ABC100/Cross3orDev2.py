def f(n):
    result=0
    while n%2==0:
        n=n/2
        result+=1
    return result


N=int(input())
print(sum([f(int(i)) for i in input().split(" ")]))
