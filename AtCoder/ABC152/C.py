N=int(input())
P=[int(i) for i in input().split(" ")]

minimum=10**10
retval=0
for p in P:
    if p<minimum:
        minimum=p
        retval+=1

print(retval)
