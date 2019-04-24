import itertools
N,A,B,C=[int(i) for i in input().split(" ")]
bamboo=[]
bamboo=sorted(bamboo,reverse=True)
for i in range(N):
    bamboo.append(int(input()))

def costWithMagic1and2(bamboo,A,B,C):
    retval=10**10
    for i in itertools.combinations([j for j in range(len(bamboo))],3):
        a,b,c=bamboo[i[0]],bamboo[i[1]],bamboo[i[2]]
        retval=min(retval,(abs(A-a)+abs(B-b)+abs(C-c)))
    return retval

ans=10**10

for i in itertools.product([0,1],repeat=N-1):
        _bamboo=[]
        tmp=bamboo[0]
        for j,m in enumerate(i):
            if m==0:
                _bamboo.append(tmp)
                tmp=bamboo[j+1]
            else:
                tmp+=bamboo[j+1]
        _bamboo.append(tmp)
        ans=min(ans,costWithMagic1and2(_bamboo,A,B,C)+(N-len(_bamboo))*10)
print(ans)
