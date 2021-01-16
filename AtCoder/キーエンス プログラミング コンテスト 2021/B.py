from collections import Counter
N,K=[int(i) for i in input().split(" ")]
a=[int(i) for i in input().split(" ")]

d=dict(Counter(a))

retval=0
for i in range(K):
    for j in range(3*(10**5)+10):
        if d.get(j,0)==0:
            retval+=j
            break
        else:
            d[j]-=1

print(retval)
