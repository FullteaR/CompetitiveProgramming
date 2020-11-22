from collections import Counter

N,X=[int(i) for i in input().split(" ")]
S=input()

for c in S:
    if c=='o':
        X+=1
    else:
        if X>0:
            X-=1

print(X)
