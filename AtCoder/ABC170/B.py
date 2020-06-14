a,b=[int(i) for i in input().split(" ")]
x=2*a-b/2
y=b/2-a

if int(x)==x and int(y)==y and x>=0 and y>=0:
    print("Yes")
else:
    print("No")
