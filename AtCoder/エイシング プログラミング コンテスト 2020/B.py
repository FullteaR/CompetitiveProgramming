N=int(input())
a=[int(i) for i in input().split(" ")]

retval=0
for i,ai in enumerate(a):
    if (i+1)%2==1 and ai%2==1:
        retval+=1
print(retval)
