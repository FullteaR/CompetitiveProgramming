import math
N,K=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]

def f(x):
    retval=0
    for a in A:
        retval+=a^x
    return retval

ans=0
kouho=[K]
for i in range(int(math.log2(K - 0.1) + 1)):
    kouho.append(2**i)
    kouho.append(2**i-1)

for i in kouho:
    print(i,f(i))
    ans=max(f(i),ans)
print(ans)
