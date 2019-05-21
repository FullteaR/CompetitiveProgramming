import sys

while True:
    n=int(input())
    score={}
    if n==0:
        sys.exit()
    for _ in range(n):
        e,p,q=[int(i) for i in input().split(" ")]
        score[e]=score.get(e,0)+p*q

    employee=[]
    for e in score:
        if score[e]>=1000000:
            employee.append(e)

    if len(employee)==0:
        print("NA")
    else:
        for e in employee:
            print(e)
