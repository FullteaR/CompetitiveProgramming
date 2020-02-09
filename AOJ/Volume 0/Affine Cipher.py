n=int(input())

def GCD(a,b):
    if min(a,b)==0:
        return max(a,b)
    else:
        return GCD(min(a,b),max(a,b)%min(a,b))

def affine(a,b,word):
    retval=""
    for w in word:
        retval+=chr(ord('a')+((ord(w)-ord('a'))*a+b)%26)
    return retval

for i in range(n):
    encrypted=input().split(" ")
    for a in range(1,27):
        for b in range(1,27):
            if GCD(a,26)!=1:
                continue
            plain=[affine(a,b,s) for s in encrypted]
            if ("this" in plain) or ("that" in plain):
                print(" ".join(plain))
                break
