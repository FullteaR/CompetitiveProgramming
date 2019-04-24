time=[]
back=0
for i in range(5):
    A=int(input())
    if A%10==0:
        pass
    else:
        back=max(back,10-A%10)
        A=(A//10)*10 +10

    time.append(A)

print(sum(time)-back)
