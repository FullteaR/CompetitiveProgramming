def ans(p,q):
    p=p%q
    _q=q

    mods=[p%q]
    score=""
    while True:
        p*=10
        score+=str(p//q)
        p=p%q
        if p in mods:
            break
        else:
            mods.append(p)

    mods=[]
    score2=""
    while True:
        p*=10
        score2+=str(p//q)
        p=p%q
        if p in mods:
            break
        else:
            mods.append(p)
    score2=score2[:-1]
    if score2=="0":
        ans=score[:-1]
    else:
        ans="{0}\n{1}"
        padding=" "*(len(score)-len(score2))+"^"*len(score2)
        ans=ans.format(score,padding)
    return ans


while True:
    try:
        p,q=[int(i) for i in input().split(" ")]
        print(ans(p,q))
    except EOFError:
        break
