N=int(input())
A=input()
B=input()
C=input()
retval=0
for a,b,c in zip(A,B,C):
    if a==b and b==c:
        continue
    elif a==b or b==c or c==a:
        retval+=1
    else:
        retval+=2

print(retval)
