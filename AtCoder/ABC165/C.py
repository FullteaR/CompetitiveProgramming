import itertools

N,M,Q=[int(i) for i in input().split(" ")]

abcd=[]

for i in range(Q):
    abcd.append([int(j) for j in input().split(" ")])




def score(A):
    retval=0
    for i in range(Q):
        a,b,c,d=abcd[i]
        if A[b-1]-A[a-1]==c:
            retval+=d
    return retval

retval=0
for iter in itertools.combinations_with_replacement([i for i in range(1,M+1)],N):
    retval=max(score(sorted(iter)),retval)

print(retval)
