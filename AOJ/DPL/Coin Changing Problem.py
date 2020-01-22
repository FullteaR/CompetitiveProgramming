n,m=[int(i) for i in input().split(" ")]
c=sorted([int(i) for i in input().split(" ")])
c.pop(0)
table=[[0 for j in range(n+1)] for i in range(m)]
for j in range(n+1):
    table[0][j]=j
for i in range(1,m):
    for j in range(n+1):
        if j>=c[i-1]:
            table[i][j]=min(table[i-1][j],table[i-1][j-c[i-1]]+1,table[i][j-c[i-1]]+1)
        else:
            table[i][j]=table[i-1][j]

print(table[-1][-1])
