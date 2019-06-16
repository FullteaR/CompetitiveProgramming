N,M=[int(i) for i in input().split(" ")]
S=[int(i) for i in input().split(" ")]
T=[int(i) for i in input().split(" ")]

table=[[0 for i in range(N+1)] for j in range(M+1)]
for j in range(M+1):
    table[j][0]=1
for i in range(N+1):
    table[0][i]=1

for i in range(1,M+1):
    for j in range(1,N+1):
        if T[i-1]==S[j-1]:
            table[i][j]+=table[i-1][j-1]
        table[i][j]+=table[i][j-1]+table[i-1][j]-table[i-1][j-1]



print(table[-1][-1]%(10**9+7))
