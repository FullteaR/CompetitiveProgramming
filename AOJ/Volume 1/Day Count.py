import datetime

while True:
    y1,m1,d1,y2,m2,d2=[int(i) for i in input().split(" ")]
    if y1==-1:
        break
    d1=datetime.datetime(y1,m1,d1)
    d2=datetime.datetime(y2,m2,d2)
    print((d2-d1).days)
