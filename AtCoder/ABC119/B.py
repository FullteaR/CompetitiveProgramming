N=int(input())
otoshidama=0
for i in range(N):
    x,u=input().split(" ")
    x=float(x)
    if u=="JPY":
        otoshidama+=x
    else:
        otoshidama+=(380000*x)

print(otoshidama)
