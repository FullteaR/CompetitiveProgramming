import sys
txa,tya,txb,tyb,T,V=[int(i) for i in input().split(" ")]
n=int(input())

def distance(p1,p2):
    return ((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)**0.5

for i in range(n):
    x,y=[int(j) for j in input().split(" ")]
    if distance((x,y),(txa,tya)) + distance((x,y),(txb,tyb)) <=V*T:
        print("YES")
        sys.exit()

print("NO")
