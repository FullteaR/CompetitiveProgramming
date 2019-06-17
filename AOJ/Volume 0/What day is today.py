import datetime

num2wd={0:"Monday",1:"Tuesday",2:"Wednesday",3:"Thursday",4:"Friday",5:"Saturday",6:"Sunday"}

while True:
    m,d=[int(i) for i in input().split(" ")]
    if m==0 and d==0:
        break

    date=datetime.datetime(2004,m,d)
    print(num2wd[date.weekday()])
