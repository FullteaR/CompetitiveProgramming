N=int(input())
tasks={}
for i in range(N):
    A,B=[int(i) for i in input().split(" ")]
    tasks[B]=tasks.get(B,0)+A

time=0
tasks=sorted(tasks.items(),key=lambda w:w[0])
for task in tasks:
    time+=task[1]
    if time>task[0]:
        print("No")
        break
else:
    print("Yes")
