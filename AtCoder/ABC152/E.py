N=int(input())
A=[int(i) for i in input().split(" ")]
mod=10**9+7

def GCD(a,b):
    if min(a,b)==0:
        return max(a,b)
    else:
        return GCD(min(a,b),max(a,b)%min(a,b))

def LCM(a,b):
    return int(a*b//GCD(a,b))





lcm=1
for a in A:
    lcm=LCM(lcm,a)


retval=0
for a in A:
    retval+=lcm//a

print(int(retval%mod))
