D,N=[int(i) for i in input().split(" ")]
num=1
i=1
while i<N:
    num+=1
    if num%100!=0:
        i+=1

print(num*(100**D))
