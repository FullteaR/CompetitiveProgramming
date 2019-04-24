import itertools
N=int(input())
C=[]
C.append(int(input()))
for i in range(N-1):
    c=int(input())
    #if C[-1]!=c:
        #C.append(c)
    C.append(c)







"""
def returnAllIndex(C):
    retval={}
    for i,c in enumerate(C):
        tmp=retval.get(c,[])
        tmp.append(i)
        retval[c]=tmp
    return retval

retval=[]

def solve(C):
    retval.append(C)
    if len(C)==len(set(C)):
        return

    allIndex=returnAllIndex(C)

    for color in allIndex:
        count=len(allIndex[color])
        if count>1:
            for i in itertools.combinations([j for j in range(count)],2):
                p,q=i
                solve(C[:allIndex[color][p]:]+C[allIndex[color][q]::])
    return

solve(C)
print(set(list(map(tuple,retval))))
"""
