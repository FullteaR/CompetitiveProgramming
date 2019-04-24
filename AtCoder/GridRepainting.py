import copy
import sys
def advance(visited,now):
    result=W*H+1
    if now==W*H-1:
        result=min( len(visited),result)
    else:
        for i in range(W*H):
            if i in visited:
                continue
            elif G[i][now]==1:
                _visited=copy.copy(visited)
                _visited.append(now)
                result=advance(_visited,i)
    return result

H,W=[int(i) for i in input().split(" ")]
Map=[]
white=0
for i in range(H):
    l=[]
    s=input()
    for j in s:
        if j==".":
            l.append(0)
            white+=1
        else:
            l.append(-1)

    Map.append(l)
Map[0][0]=1
G=[[0 for i in range(H*W)] for j in range(H*W)]

for i in range(H):
    for j in range(W):
        if Map[i][j]==-1 :
            continue
        else:
            try:
                if Map[i+1][j]==0:
                    G[W*i+j][W*(i+1)+j]=1
                    G[W*(i+1)+j][W*i+j]=1
            except IndexError:
                pass
            try:
                if Map[i][j+1]==0:
                    G[W*i+j][W*i+j+1]=1
                    G[W*i+j+1][W*i+j]=1
            except IndexError:
                pass

advanced=[[0,0]]
step=2
while Map[-1][-1]==0:
    _advanced=[]
    for i in advanced:
        try:
            if Map[i[0]+1][i[1]]==0:
                Map[i[0]+1][i[1]]=step
                _advanced.append([i[0]+1,i[1]])
        except IndexError:
            pass
        try:
            if Map[i[0]][i[1]+1]==0:
                Map[i[0]][i[1]+1]=step
                _advanced.append([i[0],i[1]+1])
        except IndexError:
            pass
        try:
                if Map[i[0]-1][i[1]]==0 and i[0]!=0:
                    Map[i[0]-1][i[1]]=step
                    _advanced.append([i[0]-1,i[1]])
        except IndexError:
                pass
        try:
                if Map[i[0]][i[1]-1]==0 and i[1]!=0:
                    Map[i[0]][i[1]-1]=step
                    _advanced.append([i[0],i[1]-1])
        except IndexError:
                pass
    step+=1
    advanced=copy.deepcopy(_advanced)
    if len(advanced)==0:
        print(-1)
        sys.exit()
print(white-Map[-1][-1])
