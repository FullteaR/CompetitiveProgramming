import sys
N,M,T=[int(i) for i in input().split(" ")]
caffe=[]
for i in range(M):
    caffe.append([int(j) for j in input().split(" ")])

battery=N
left=0

for c in caffe:
    A,B=c
    battery-=A-left
    if battery<=0:
        print("No")
        sys.exit()
    battery+=B-A
    if battery>N:
        battery=N
    left=B

battery-=T-left
if battery<=0:
    print("No")
else:
    print("Yes")
