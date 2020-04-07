N,K=[int(i) for i in input().split(" ")]

N=N%K
print(min(N,K-N))
