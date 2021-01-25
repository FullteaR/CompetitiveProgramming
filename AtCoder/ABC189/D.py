from functools import lru_cache
N=int(input())
S=[]
for i in range(N):
    S.append(input())


@lru_cache()
def solve(i,bool):
    if i==0:
        return 1
    if bool==True:
        if S[i-1]=="AND":
            return solve(i-1, True)
        else:
            return 2*solve(i-1, True) + solve(i-1, False)

    else:
        if S[i-1]=="AND":
            return solve(i-1,False)*2 + solve(i-1,True)
        else:
            return solve(i-1, False)

print(solve(N,True))
