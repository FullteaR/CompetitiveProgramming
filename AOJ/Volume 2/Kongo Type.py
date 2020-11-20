N=int(input())
for i in range(N):
    s=str(bin(int(input(),16)))[2::]
    s="0"*(32-len(s))+s
    pm=s[0]
    num=int(s[1::],2)
    num=num/(2**7)
    if(pm=='1'):
        print("-",end="")
    print(num)
