n=int(input())

tuples=[]

for _ in range(n):
    obj=input().split(" ")
    obj[0]=int(obj[0])
    obj[1]=int(obj[1])
    obj[3]=int(obj[3])
    tuples.append(obj)

tuples=sorted(tuples)

for t in tuples:
    print(t[0],t[1],t[2],t[3],t[4])
