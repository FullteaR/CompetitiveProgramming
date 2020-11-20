from collections import deque
from copy import deepcopy
water=[0 for i in range(2*(10**5))]
N,W=[int(i) for i in input().split(" ")]

people_origin=[]
for i in range(N):
    people_origin.append([int(j) for j in input().split(" ")])

people=deque(sorted(people_origin, key=lambda w:w[0]))

amount=0
for t in range(2*(10**5)):
    while len(people)>0 and people[0][0]==t:
        amount+=people.popleft()[2]
    water[t]+=amount

people=deque(sorted(people_origin, key=lambda w:w[1]))

amount=0
for t in range(2*(10**5)):
    while len(people)>0 and people[0][1]==t:
        amount+=people.popleft()[2]
    water[t]-=amount

if max(water)<=W:
    print("Yes")
else:
    print("No")
