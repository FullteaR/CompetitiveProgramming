N=int(input())

A=[]
B=[]

for i in range(N):
    _A,_B=[int(j) for j in input().split(" ")]
    A.append(_A)
    B.append(_B)

def findall(l,x):
    retval=[]
    for i,j in enumerate(l):
        if j==x:
            retval.append(i)
    return set(retval)

As=findall(A,min(A))
Bs=findall(B,min(B))
if len(As-Bs)>0 and len(Bs-As)>0:
    print(max(min(A),min(B)))
else:
    A=sorted(A)
    B=sorted(B)
    print(min([A[0]+B[0],max(A[0],B[1]),max(A[1],B[0])]))
