from functools import lru_cache

mod=1000000007

@lru_cache()
def pow2(i):
    if i==0:
        return 1
    elif i==1:
        return 2

    if i%2==0:
        return (pow2(i//2)*pow2(i//2))%mod
    else:
        return (pow2(i-1)*2)%mod


H,W=[int(i) for i in input().split(" ")]
H+=2
W+=2
S=[[False for i in range(W)]]
for i in range(H-2):
    S.append([False]+[j=="." for j in input()]+[False])
S.append([False for i in range(W)])

K=sum([sum(s) for s in S])


total=[[[0,0] for i in range(W)] for j in range(H)]
for h in range(1,H-1):
    for w in range(1,W-1):
        if S[h][w]==False:
            continue
        if S[h][w-1]==False:
            yoko=0
            while S[h][w+yoko]:
                yoko+=1
            total[h][w][0]=yoko
        else:
            total[h][w][0]=total[h][w-1][0]

        if S[h-1][w]==False:
            tate=0
            while S[h+tate][w]:
                tate+=1
            total[h][w][1]=tate
        else:
            total[h][w][1]=total[h-1][w][1]

retval=0
for h in range(1,H-1):
    for w in range(1,W-1):
        if S[h][w]==False:
            continue

        masu=total[h][w][0]+total[h][w][1]-1
        retval+=((pow2(masu)-1)*pow2(K-masu))%mod
        retval=retval%mod

print(retval)
