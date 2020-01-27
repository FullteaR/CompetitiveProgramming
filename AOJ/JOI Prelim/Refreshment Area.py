N,M,D = [int(i) for i in input().split(" ")]
space=[]
for i in range(N):
    S=input()
    row=[]
    for s in S:
        if s==".":
            row.append(0)
        else:
            row.append(1)
    space.append(row)

retval=0
for i in range(N):
    for j in range(M):
        if space[i][j]==1:
            continue
        try:
            for k in range(D):
                if space[i+k][j]==1:
                    break
            else:
                retval+=1
        except IndexError:
            pass
        try:
            for k in range(D):
                if space[i][j+k]==1:
                    break
            else:
                retval+=1
        except IndexError:
            pass

print(retval)
