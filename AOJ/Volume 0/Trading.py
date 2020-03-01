lastMonth={}
thisMonth={}

month="last"

while True:
    try:
        s=input()
        if s=="":
            month="this"
            continue
        c,d=[int(i) for i in s.split(",")]
        if month=="last":
            lastMonth[c]=lastMonth.get(c,0)+1
        else:
            thisMonth[c]=thisMonth.get(d,0)+1
    except EOFError:
        break


for key in sorted(list(set(thisMonth.keys()) & set(lastMonth.keys()))):
    print(key,thisMonth[key]+lastMonth[key])
