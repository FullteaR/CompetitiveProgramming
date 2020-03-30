X,Y,A,B,C=[int(i) for i in input().split(" ")]
red=[int(i) for i in input().split(" ")]
green=[int(i) for i in input().split(" ")]
white=[int(i) for i in input().split(" ")]

red=sorted(red,reverse=True)[:X]
green=sorted(green,reverse=True)[:Y]

color=[(r,'r') for r in red]+[(g,'g') for g in green]
color=sorted(color,key=lambda w:w[0],reverse=False)
white=sorted(white,reverse=True)

delicious=0


for c in color:
    if(c[1]=='r'):
        if X==0:
            continue
        X-=1
        if(len(white)>0 and c[0]<white[0]):
            delicious+=white[0]
            white.pop(0)
        else:
            delicious+=c[0]

    else:
        if Y==0:
            continue
        Y-=1
        if(len(white)>0 and c[0]<white[0]):
            delicious+=white[0]
            white.pop(0)
        else:
            delicious+=c[0]


print(delicious)
