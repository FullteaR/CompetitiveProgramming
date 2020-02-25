from datetime import datetime

def gengo(y,m,d):
    date=datetime(y,m,d)
    if date<datetime(1868,9,8):
        return "pre-meiji"
    elif date<=datetime(1912,7,29):
        return "meiji {0} {1} {2}".format(y-1867,m,d)
    elif date<=datetime(1926,12,24):
        return "taisho {0} {1} {2}".format(y-1911,m,d)
    elif date<=datetime(1989,1,7):
        return "showa {0} {1} {2}".format(y-1925,m,d)
    else:
        return "heisei {0} {1} {2}".format(y-1988,m,d)

while True:
    try:
        y,m,d=[int(i) for i in input().split(" ")]
        print(gengo(y,m,d))
    except EOFError:
        break
