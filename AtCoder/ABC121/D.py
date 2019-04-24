A,B=[int(i) for i in input().split(" ")]



def f0_n(B,n):
    if n==1:
        return  ((B+1)//2)%2


    B=(B+1)%(2**n)
    if B<=2**(n-1):
        return 0
    else:
        B-=2**(n-1)
        return B%2



def f0(B):
    retval=""
    for n in range(1,len(bin(B).replace("b",""))+10):
        retval+=str(f0_n(B,n))
    retval=retval[::-1]
    return int(retval,2)


if A==0:
    print(f0(B))
else:
    print(f0(B)^f0(A-1))
