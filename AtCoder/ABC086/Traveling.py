import sys
def travel(xs,ys,xf,yf,t):
    d=abs(xf-xs)+abs(yf-ys)
    if d>t:
        return False
    else:
        if d%2==t%2:
            return True
        else:
            return False

N=int(input())
txy=[[0,0,0]]
for i in range(N):
    txy.append([int(j) for j in input().split(" ")])

for i in range(N):
    if travel(txy[i][1],txy[i][2],txy[i+1][1],txy[i+1][2],txy[i+1][0]-txy[i][0])==False:
        print("No")
        sys.exit()
print("Yes")
