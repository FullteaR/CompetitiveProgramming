import sys
N=int(input())
a=[int(i) for i in input().split(" ")]

if 1 in a:
    pass
else:
    print("-1")
    sys.exit()

i=1
retval=0
for ai in a:
    if ai==i:
        i+=1
    else:
        retval+=1

print(retval)
