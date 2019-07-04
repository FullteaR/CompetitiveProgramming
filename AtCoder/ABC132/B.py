n=int(input())
p=[int(i) for i in input().split(" ")]

retval=0
for i in range(1,n-1):
    if p[i-1]>p[i] and p[i]>p[i+1]:
        retval+=1
    elif p[i-1]<p[i] and p[i]<p[i+1]:
        retval+=1

print(retval)
