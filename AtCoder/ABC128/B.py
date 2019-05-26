N=int(input())
rest={}
for i in range(N):
    S,P=input().split(" ")
    P=int(P)
    tmp=rest.get(S,[])
    tmp.append((P,i+1))
    rest[S]=tmp
for key in sorted(rest.keys()):
    Rs=rest[key]
    for s in sorted(Rs,reverse=True):
        print(s[1])
