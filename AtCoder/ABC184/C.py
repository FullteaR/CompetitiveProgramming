r1,c1=[int(i) for i in input().split(" ")]
r2,c2=[int(i) for i in input().split(" ")]
import sys

def reachable(r1,c1,r2,c2):
    return r1+c1==r2+c2 or r1-c1==r2-c2 or abs(r1-r2)+abs(c1-c2)<=3

if r1==r2 and c1==c2:
    print(0)
    sys.exit()


if reachable(r1,c1,r2,c2):
    print(1)
    sys.exit()

for tate in range(0,4):
    yoko=3-tate
    assert yoko>=0
    r3=r2+tate
    c3=c2+yoko
    if reachable(r1,c1,r3,c3):
        print(2)
        sys.exit()
    r3=r2-tate
    c3=c2+yoko
    if reachable(r1,c1,r3,c3):
        print(2)
        sys.exit()
    r3=r2+tate
    c3=c2-yoko
    if reachable(r1,c1,r3,c3):
        print(2)
        sys.exit()
    r3=r2-tate
    c3=c2-yoko
    if reachable(r1,c1,r3,c3):
        print(2)
        sys.exit()

if (r1+c1)%2==(r2+c2)%2:
    print(2)
else:
    print(3)
