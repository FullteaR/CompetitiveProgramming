W,H,x,y=[int(i) for i in input().split(" ")]


x=abs(x-W/2)
y=abs(y-H/2)
W=W/2
H=H/2


print(W*H*2,end=" ")

if x==0 and y==0:
    print("1")
else:
    print("0")
