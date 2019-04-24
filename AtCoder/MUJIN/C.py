N,M=[int(i) for i in input().split(" ")]

Map=[]
for i in range(N):
    Map.append("{}".format(input()))

count=0

for _x in range(N):
    for _y in range(M):
        if Map[_x][_y]=="#":
            continue

        u=0
        d=0
        r=0
        l=0

        x=_x-1
        y=_y
        flag =True
        while x>=0 and flag:
            if Map[x][y]==".":
                u+=1
            else:
                flag=False
            x-=1

        x=_x+1
        y=_y
        flag=True
        while x<N and flag:
            if Map[x][y]==".":
                d+=1
            else:
                break
            x+=1

        x=_x
        y=_y-1
        while y>=0:
            if Map[x][y]==".":
                l+=1
            else:
                break
            y-=1

        x=_x
        y=_y+1
        while y<M:
            if Map[x][y]==".":
                r+=1
            else:
                break
            y+=1

        count+=r*u+l*u+r*d+l*d

print(count)
