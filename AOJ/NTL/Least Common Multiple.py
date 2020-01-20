n=int(input())

def GCD(a,b):
    if min(a,b)==0:
        return max(a,b)
    else:
        return GCD(min(a,b),max(a,b)%min(a,b))

def LCM(a,b):
    return (a*b)//GCD(a,b)

a=[int(i) for i in input().split(" ")]

lcm=1
for ai in a:
    lcm=LCM(ai,lcm)
print(lcm)
