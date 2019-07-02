d={}
n=int(input())
for i in range(n):
    com,gen=input().split(" ")
    if com=="insert":
        d[gen]=d.get(gen,0)+1
    if com=="find":
        if gen in d:
            print("yes")
        else:
            print("no")
