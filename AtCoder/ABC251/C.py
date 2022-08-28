from re import sub


N=int(input())

submissions = set()

maxscore=-1

for i in range(N):
    S,T=input().split(" ")
    T=int(T)
    if S in submissions:
        continue
    submissions.add(S)
    if T>maxscore:
        maxscore=T
        index = i

print(index+1)