M,D=[int(i) for i in input().split(" ")]

retval=0

for i in range(1,M+1):
    for j in range(1,D+1):
        a=j%10
        b=int(j/10)
        if i==a*b and a>1 and b>1:
            retval+=1

print(retval)
