def line(i,j):
    retval=[]
    if i<=5 and j<=5:
        if i<j:
            for k in range(i,j+1):
                retval.append(k)
        else:
            for k in range(i,j-1,-1):
                retval.append(k)

    elif i<=5 and j>5:
        for k in range(i,j+1):
            retval.append(k)

    elif i>5 and j>5:
        if i<j:
            for k in range(i,j+1):
                retval.append(k)
        else:
            for k in range(i,10):
                retval.append(k)
            retval+=[5,4,3,2,1,0,1,2,3,4,5]
            for k in range(6,j+1):
                retval.append(k)
    else:
        for k in range(i,10):
            retval.append(k)
        for k in range(5,j-1,-1):
            retval.append(k)


    return " ".join([str(i) for i in retval])

N=int(input())
for i in range(N):
    print(line(*[int(j) for j in input().split(" ")]))
