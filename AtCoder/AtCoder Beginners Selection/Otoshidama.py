import sys

N,Y=(int(i) for i in input().split(" "))
for i in range(N+1):
    for j in range(N+1):
            if i+j>N:
                break
            elif i*10000+j*5000+(N-i-j)*1000==Y:
                print(i,j,N-i-j)
                sys.exit()

print(-1,-1,-1)
