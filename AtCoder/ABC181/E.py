import bisect
N,M=[int(i) for i in input().split(" ")]
H=[int(i) for i in input().split(" ")]
W=[int(i) for i in input().split(" ")]
H=sorted(H)
H135=[0]
H246=[0]
for i, h in enumerate(H):
    if i%2==1:
        H135.append(H135[-1]+h)
    else:
        H246.append(H246[-1]+h)

retval=10**10
for w in W:
    index = bisect.bisect_left(H,w)
    if index%2==1:
        _retval=w
        _retval+=2*H135[index//2]
        _retval-=2*H246[index//2+1]
        _retval+=H246[-1]
        _retval-=H135[-1]
    else:
        _retval=-1*w
        _retval+=2*H135[index//2]
        _retval-=2*H246[index//2]
        _retval+=H246[-1]
        _retval-=H135[-1]
    retval=min(_retval,retval)



print(retval)
