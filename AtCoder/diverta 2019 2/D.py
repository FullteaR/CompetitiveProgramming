import itertools
N=int(input())
ga,sa,ba=[int(i) for i in input().split(" ")]
gb,sb,bb=[int(i) for i in input().split(" ")]
cmd=["getgold","paygold","getsilver","paysilver","getbronze","paybronze","fin"]
cmds=[]
for g in ("getgold","paygold","fin"):
    for s in ("getsilver","paysilver","fin"):
        for b in ("getbronze","paybronze","fin"):
            cmds.append((g,s,b))
            cmds.append((g,b,s))
            cmds.append((s,g,b))
            cmds.append((s,b,g))
            cmds.append((b,g,s))
            cmds.append((b,s,g))



def award(donguri,gold,silver,bronze,cmd,X):
    if X=="A":
        g,s,b=ga,sa,ba
    else:
        g,s,b=gb,sb,bb
    for c in cmd:
        if c=="fin":
            return donguri,gold,silver,bronze
        elif c=="getgold":
            gold+=donguri//g
            donguri=donguri%g
        elif c=="paygold":
            donguri+=gold*g
            gold=0
        elif c=="getsilver":
            silver+=donguri//s
            donguri=donguri%s
        elif c=="paysilver":
            donguri+=silver*s
            silver=0
        elif c=="getbronze":
            bronze+=donguri//b
            donguri=donguri%b
        elif c=="paybronze":
            donguri+=bronze*b
            bronze=0
    return donguri,gold,silver,bronze


retval=0
for cmd1 in cmds:
    for cmd2 in cmds:
        donguri=N
        gold=0
        silver=0
        bronze=0
        donguri,gold,silver,bronze=award(donguri,gold,silver,bronze,cmd1,"A")
        donguri,gold,silver,bronze=award(donguri,gold,silver,bronze,cmd2,"B")
        donguri+=ga*gold+sa*silver+ba*bronze
        retval=max(retval,donguri)

print(retval)
