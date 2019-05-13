N=int(input())
S=input()
num=S.count("E")
result=N
for i in range(N):
    if S[i]=="E":
        num-=1
    result=min(num,result)
    if S[i]=="W":
        num+=1

print(result)
