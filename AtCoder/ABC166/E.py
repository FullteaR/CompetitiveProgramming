from collections import Counter
N=int(input())
A=[int(i) for i in input().split(" ")]

A2=[i-A[i] for i in range(N)]
A3=[i+A[i] for i in range(N)]

c2=Counter(A2)
c3=Counter(A3)

retval=0
for key in c2+c3:
    retval+=c2[key]*c3[key]

print(retval)
