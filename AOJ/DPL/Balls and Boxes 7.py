mod=1000000007

n,k=[int(i) for i in input().split(" ")]



facts=[1 for i in range(n+k+1)]

for i in range(1,n+k+1):
    facts[i]=i*facts[i-1]


tables=[[-1 for i in range(k+1)] for j in range(n+1)]

for i in range(1,n+1):
    for j in range(1,k+1):
        if i<j:
            tables[i][j]=0
        elif j==1:
            tables[i][j]=1

        elif i==j:
            tables[i][j]=facts[i]

        else:
            tables[i][j]=j*(tables[i-1][j]+tables[i-1][j-1])

def f(n,k):
    if n<k:
        return 0
    if k==1:
        return 1

    elif n==k:
        return facts[n]

    elif tables[n][k]!=-1:
            return tables[n][k]

    else:
        retval=(k*f(n-1,k)+k*f(n-1,k-1))
        tables[n][k]=retval
        return retval

retval=0
for i in range(1,k+1):
    retval+=(tables[n][i]//facts[i])%mod

print(retval%mod)
