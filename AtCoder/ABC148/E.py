import sys


N=int(input())

def f2(n):
    if n%2==1:


if N%2==1:
    print(0)
    sys.exit()


N=N//2
retval=0
i=1
while 5**i<=N:
    retval+= N//(5**i)
    i+=1

print(retval)
