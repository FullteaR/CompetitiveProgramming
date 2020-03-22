def kaibun(s):
    return s==s[::-1]

s=input()
N=len(s)
if kaibun(s) and kaibun(s[:(N-1)//2]) and kaibun(s[-1+(N+3)//2:]):
    print("Yes")
else:
    print("No")
