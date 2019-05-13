import sys
import copy
N,M=[int(i) for i in input().split(" ")]
if M==0:
    print("No")
    sys.exit()
x=[10**9+10 for i in range(N+1)]

LRD=[]


for i in range(M):
    LRD.append([int(i) for i in input().split(" ")])
consider=[LRD[0][0]]
x[LRD[0][0]]=0

while len(LRD)!=0:
    if len(consider)==0:
        consider=[LRD[0][0]]

    _consider=consider[0]
    _LRD=copy.deepcopy(LRD)
    for i in LRD:
        if i[0]==_consider:
            if x[i[1]]>10**9:
                x[i[1]]=x[i[0]]+i[2]
                if i[1] in consider:
                    pass
                else:
                    consider.append(i[1])
            elif x[i[1]]==x[i[0]]+i[2]:
                pass
            else:
                print("No")
                sys.exit()
            _LRD.remove(i)
        elif i[1]==_consider:
            if x[i[0]]>10**9:
                x[i[0]]=x[i[1]]-i[2]
                if i[0] in consider:
                    pass
                else:
                    consider.append(i[0])
            elif x[i[0]]==x[i[1]]-i[2]:
                pass
            else:
                print("No")
                sys.exit()
            _LRD.remove(i)
        else:
            pass
    consider.pop(0)
    LRD=_LRD
print("Yes")
