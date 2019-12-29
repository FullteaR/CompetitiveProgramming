table=[1 for i in range(10**5+10)]

table[0]=0
table[1]=0
for i in range(int(len(table)**0.5)+10):
    if table[i]==0:
        continue

    k=2
    while True:
        try:
            table[k*i]=0
            k+=1
        except IndexError:
            break

X=int(input())

while table[X]==0:
    X+=1
print(X)
