import itertools

while True:
    n,s=[int(i) for i in input().split(" ")]
    if n==0 and s==0:
        break
    retval=0
    for i in itertools.combinations([j for j in range(10)],n):
        if sum(i)==s:
            retval+=1
    print(retval)
