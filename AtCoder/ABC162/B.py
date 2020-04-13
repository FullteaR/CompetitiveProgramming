s=0
N=int(input())
for a in range(1,N+1):
    if a%3!=0 and a%5!=0:
        s+=a
print(s)
