n=int(input())
answer=0
hani=10**2

max=0
number=[]
for i in range(n):
    t=int(input())
    if t>max:
        max=t
    number.append(t)


hani=max
k=2
numlist=[0 for i in range(hani+1)]
numlist[0]=-1
numlist[1]=-1


read=2
while read<=hani**(0.5):
    if numlist[read]==0:
        k=1
        while read*(k+1)<=hani:
            numlist[read*(k+1)]=-1
            k+=1
    read+=1

for i in range(n):
    if numlist[number[i]]==0:
        answer+=1



print(answer)
