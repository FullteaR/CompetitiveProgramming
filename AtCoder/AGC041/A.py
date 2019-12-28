N,A,B=[int(i) for i in input().split(" ")]
delta=abs(A-B)
if delta%2==0:
    print(delta//2)
else:
    #use1
    use1=A+(B-A-1)//2
    useN=N-B+1+(delta-1)//2
    print(min(use1,useN))
