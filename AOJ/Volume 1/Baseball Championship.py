from collections import Counter

while True:
    n=int(input())
    if n==0:
        break

    scores=[]
    for i in range(n):
        s=input().split(" ")
        team=s[0]
        score=s[1:]
        c=Counter(score)
        c=dict(c)
        result=[team,c.get('0',0),c.get('1',0),c.get('2',0)]
        scores.append(result)
    scores=sorted(scores,key=lambda w: w[1]*100+w[3],reverse=True)
    for s in scores:
        print(s[0])
