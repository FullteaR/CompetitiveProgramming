N=int(input())
S=input()
count={}
for s in S:
    count[s]=count.get(s,0)+1
retval=1
for c in count:
    retval*=(count[c]+1)
print((retval-1)%(10**9+7))
