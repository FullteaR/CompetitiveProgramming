n=int(input())
for _ in range(n):
    s=input()
    s=s.replace("-","")
    train=["" for i in range(60)]
    pointer=30
    for i in s:
        if i=="<":
            pointer-=1
        elif i==">":
            pointer+=1
        else:
            train[pointer]=i
    print("".join(train))
