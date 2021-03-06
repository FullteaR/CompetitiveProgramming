N=int(input())


E = 0
for i in range(1,N):
    p=i/N
    E+=(1-p)/((1-p)**2)

print(E)
