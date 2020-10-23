N=int(input())

ans=set()
for i in range(1,int(N**0.5)+10):
    if N%i==0:
        ans.add(i)
        ans.add(N//i)

for a in sorted(list(ans)):
    print(a)
