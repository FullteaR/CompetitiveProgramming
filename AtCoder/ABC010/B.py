def f(a):
    retval=0
    while (a%2==0 or a%3==2):
        a-=1
        retval+=1
    return retval


n=int(input())
a=[f(int(i)) for i in input().split(" ")]
print(sum(a))
