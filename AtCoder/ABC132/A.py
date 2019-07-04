import collections

S=input()
c=collections.Counter(S)
c=dict(c)
for key in c:
    if c[key]!=2:
        print("No")
        break
else:
    print("Yes")
