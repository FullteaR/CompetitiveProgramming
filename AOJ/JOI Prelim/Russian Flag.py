N,M=[int(i) for i in input().split(" ")]

blue=[0]
white=[0]
red=[0]
for i in range(N):
    S=input()
    blue.append(M-S.count("B")+blue[-1])
    white.append(M-S.count("W")+white[-1])
    red.append(M-S.count("R")+red[-1])

def paint(i,j):
    retval=0
    retval+=white[i]-white[0]
    retval+=blue[j]-blue[i]
    retval+=red[N]-red[j]
    return retval

retval=10**10
for i in range(1,N):
    for j in range(i+1,N):
        retval=min(paint(i,j),retval)

print(retval)
