import itertools
N=int(input())

def returnSplit(N):
    if N%2==0:
        return [[i+1,N-i] for i in range(N//2)]
    else:
        return returnSplit(N-1)+[[N]]


blocks=returnSplit(N)
retval=[]

for i in range(len(blocks)):
    for j in range(i+1,len(blocks)):
        for k in itertools.product(blocks[i],blocks[j]):
            retval.append(k)


print(len(retval))
for i in retval:
    print("{0} {1}".format(*i))
