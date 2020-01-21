from functools import lru_cache

@lru_cache()
def GCD(a,b):
    if min(a,b)==0:
        return max(a,b)
    else:
        return GCD(min(a,b),max(a,b)%min(a,b))

def extendedEuler(a,b):
    if b==GCD(a,b):
        return (0,1)
    elif a==GCD(a,b):
        return (1,0)

    if a<b:
        X,Y=extendedEuler(a,b%a)
        return (X-(b//a)*Y,Y)
    else:
        X,Y=extendedEuler(a%b,b)
        return (X,Y-(a//b)*X)

a,b=[int(i) for i in input().split(" ")]
x0,y0=extendedEuler(a,b)
print(x0,y0)
