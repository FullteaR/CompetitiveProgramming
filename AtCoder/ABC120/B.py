import sys
A,B,K=[int(i) for i in input().split(" ")]
count=0
for i in range(101,0,-1):
    if A%i==0 and B%i==0:
        count+=1
    if count==K:
        print(i)
        sys.exit()
