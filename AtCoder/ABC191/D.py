import math
X,Y,R=[float(i) for i in input().split(" ")]

X=int(10000*X+1e-7)
Y=int(10000*Y+1e-7)
R=int(10000*R+1e-7)

left = X-R
if left%10000==0:
    pass
else:
    left = math.ceil(left/10000)*10000

right = X+R
if right%10000==0:
    pass
else:
    right = math.floor(right/10000)*10000

count=0
for x in range(left,right+10000,10000):
    sqr=(R**2-(X-x)**2)**0.5
    top=Y+sqr
    bottom=Y-sqr
    if top%10000==0:
        pass
    else:
        top = math.floor(top/10000)*10000
    if bottom%10000==0:
        pass
    else:
        bottom = math.ceil(bottom/10000)*10000
    count+=top//10000-bottom//10000+1
print(int(count))
