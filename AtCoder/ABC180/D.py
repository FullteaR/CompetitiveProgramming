X,Y,A,B=[int(i) for i in input().split(" ")]



a=0
exp=0
while(X*(A**a)<Y):
    b=(Y-X*(A**a)-1)//B
    exp=max(exp,a+b)
    a+=1

print(exp)
