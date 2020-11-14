from collections import Counter
import itertools

S=input()
c=dict(Counter(S))
for key in c:
    if c[key]>3:
        c[key]=3

nums=[]
for key in c:
    nums+=[key for i in range(c[key])]

for iter in itertools.permutations(nums,min(3,len(nums))):
    n=int("".join(list(iter)))
    if n%8==0:
        print("Yes")
        break

else:
    print("No")
