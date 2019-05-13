def GCD(a, b):
    M = max(a, b)
    m = min(a, b)
    if m == 0:
        return M
    else:
        return GCD(m, M % m)


N,M=[int(i) for i in input().split(" ")]
table=[[-1 for i in range(M+1)] for i in range(N)]

for i in range(N):
    a=int(input())
    l=table[i]
    l[0]=0
    l[1]=1
    for j in range(2,M+1):
        if l[j]!=-1:
            pass
        else:
            if a%j==0:
                k=1
                flag=True
                while flag:
                    try:
                        l[k*j]=0
                        k+=1
                    except IndexError:
                        flag=False
            else:
                k=1
                flag=True
                while flag:
                    try:
                        if l[k*j]!=0:
                            l[k*j]=1
                        k+=1
                    except IndexError:
                        flag=False

result=[0 for i in range(M+1)]
for i in table:
    for j in range(M+1):
        result[j]+=i[j]

result.pop(0)
for i in result:
    print(i)
