N,X=[int(i) for i in input().split(" ")]
L=[int(i) for i in input().split(" ")]

count=1
D=0
for l in L:
    D+=l
    if D<=X:
        count+=1

print(count) 
