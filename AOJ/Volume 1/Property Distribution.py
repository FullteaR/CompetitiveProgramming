


def calc(H,W,property):
    visit=[[False for i in range(W+2)] for j in range(H+2)]
    retval=0

    _property=[['.' for i in range(W+2)]]
    for p in property:
        _property.append(['.']+p+['.'])
    _property.append(['.' for i in range(W+2)])
    property=_property
    for i in range(1,H+1):
        for j in range(1,W+1):
            if visit[i][j]:
                continue
            visit[i][j]=True
            retval+=1
            next=[(i,j)]
            while len(next)>0:
                _next=[]
                for p in next:
                    if visit[p[0]-1][p[1]]==False and property[p[0]][p[1]]==property[p[0]-1][p[1]]:
                        _next.append((p[0]-1,p[1]))
                        visit[p[0]-1][p[1]]=True
                    if visit[p[0]+1][p[1]]==False and property[p[0]][p[1]]==property[p[0]+1][p[1]]:
                        _next.append((p[0]+1,p[1]))
                        visit[p[0]+1][p[1]]=True
                    if visit[p[0]][p[1]-1]==False and property[p[0]][p[1]]==property[p[0]][p[1]-1]:
                        _next.append((p[0],p[1]-1))
                        visit[p[0]][p[1]-1]=True
                    if visit[p[0]][p[1]+1]==False and property[p[0]][p[1]]==property[p[0]][p[1]+1]:
                        _next.append((p[0],p[1]+1))
                        visit[p[0]][p[1]+1]=True
                next=_next
    return retval




while True:
    H,W=[int(i) for i in input().split(" ")]
    if H==0 and W==0:
        break
    property=[[s for s in input()] for i in range(H)]
    print(calc(H,W,property))
