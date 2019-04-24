import datetime

tstr=input()
d=datetime.datetime.strptime(tstr,"%Y/%m/%d")
if d<=datetime.datetime(2019,4,30):
    print("Heisei")
else:
    print("TBD")
