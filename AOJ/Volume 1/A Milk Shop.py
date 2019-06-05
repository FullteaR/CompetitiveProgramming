while True:
    n=int(input())
    if n==0:
        break
    t=[]
    for i in range(n):
        t.append(int(input()))
    t=sorted(t)

    retval=0
    for i in range(n):
        retval+=t[i]*(n-i-1)
    print(retval)
