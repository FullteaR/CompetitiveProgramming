def gcd(A,B):
    a=min(A,B)
    b=max(A,B)
    if a==0:
        return b
    else:
        return gcd(a,b%a)


A,B=[int(i) for i in input().split(" ")]

print(int(A*B/gcd(A,B)))
