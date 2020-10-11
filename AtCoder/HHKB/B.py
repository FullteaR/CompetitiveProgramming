H,W=[int(i) for i in input().split(" ")]
S=[]
for i in range(H):
    S.append([j for j in input()])

retval=0
for h in range(H):
    for w in range(W):

        if h<H-1 and S[h][w]=="." and S[h+1][w]==".":
            retval+=1
        if w<W-1 and S[h][w]=="." and S[h][w+1]==".":
            retval+=1

print(retval)
