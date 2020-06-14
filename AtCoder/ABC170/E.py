import bisect

youchien2engi={}
engi2youchien={}
engi2rate={}
INF=10000000010

N,Q=[int(i) for i in input().split(" ")]
for i in range(N):
    A,B=[int(j) for j in input().split(" ")]
    tmp=youchien2engi.get(B,[])
    tmp.append(i+1)
    youchien2engi[B]=tmp
    engi2youchien[i+1]=B
    engi2rate[i+1]=A

for key in youchien2engi:
    youchien2engi[key]=sorted(youchien2engi[key])

for i in range(Q):
    C,D=[int(j) for j in input().split(" ")]

    youchien_before=engi2youchien[C]
    tmp=youchien2engi[youchien_before]
    ind=bisect.bisect(tmp,C)
    del tmp[ind-1]
    if len(tmp)==0:
        del youchien2engi[youchien_before]
    else:
        youchien2engi[youchien_before]=tmp
    engi2youchien[C]=D

    tmp=youchien2engi.get(D,[])
    bisect.insort(tmp,C)
    youchien2engi[D]=tmp
    Minimum=INF
    for key in youchien2engi:
        if len(youchien2engi[key])==0:
            continue
        Maximum=0
        for engi in youchien2engi[key]:
            Maximum=max(Maximum,engi2rate[engi])
        Minimum=min(Minimum,Maximum)
    print(Minimum)
