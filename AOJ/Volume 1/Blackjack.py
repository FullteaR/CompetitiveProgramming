while True:
    n=[int(i) for i in input().split(" ")]
    if n==[0]:
        break
    for i in range(len(n)):
        if n[i]>10:
            n[i]=10
    one=n.count(1)
    score=sum(n)
    while score<=11 and one>0:
        if one>0:
            score+=10
            one-=1
    if score>21:
        score=0
    print(score)
