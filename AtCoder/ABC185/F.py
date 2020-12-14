import bisect

N,Q=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]
cum=[0]
for a in A:
    cum.append(cum[-1]^a)

changed_indexes=[]
changes={}

for q in range(Q):
    T,X,Y=[int(i) for i in input().split(" ")]
    if T==1:
        #cum[X:]=cum[X:] ^ Y
        if X-1 in changes:
            changes[X-1] = changes[X-1] ^ Y
        else:
            bisect.insort(changed_indexes,X-1)
            changes[X-1] = Y

    else:
        #print(cum[Y]^cum[X-1])
        retval=cum[Y]^cum[X-1]
        for key in changed_indexes[bisect.bisect_left(changed_indexes,X-1):bisect.bisect_right(changed_indexes,Y)]:
            if key<X-1 or key>=Y:
                continue
            retval=retval^changes[key]
        print(retval)
