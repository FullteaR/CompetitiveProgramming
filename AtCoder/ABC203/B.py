N,K=[int(i) for i in input().split(" ")]

s=0
for n in range(1,N+1):
    for k in range(1,K+1):
        s+=int("{0}0{1}".format(n,k))
print(s)