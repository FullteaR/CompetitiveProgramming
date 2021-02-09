H,W=[int(i) for i in input().split(" ")]

S=[]
for h in range(H):
    S.append([s=='#' for s in input()])

retval=0
for h in range(H-1):
    for w in range(W-1):
        retval+=(S[h][w]+S[h+1][w]+S[h][w+1]+S[h+1][w+1])%2

print(retval)
