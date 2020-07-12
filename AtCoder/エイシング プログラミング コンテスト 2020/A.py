L,R,d=[int(i) for i in input().split(" ")]
retval=0
for i in range(L,R+1):
    if i%d==0:
        retval+=1
print(retval)
