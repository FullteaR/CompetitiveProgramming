N=int(input())
for i in range(N):
    a=int(input())
    b=int(input())
    retval=a+b
    if len(str(retval))>80:
        print("overflow")
    else:
        print(retval)
