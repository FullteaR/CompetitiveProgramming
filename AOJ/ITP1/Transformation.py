s=input()
q=int(input())
for i in range(q):
    t=input().split(" ")
    if t[0]=="print":
        a,b=int(t[1]),int(t[2])
        print(s[a:b+1:])
    if t[0]=="reverse":
        a,b=int(t[1]),int(t[2])
        s=s[:a:]+s[a:b+1:][::-1]+s[b+1::]
    if t[0]=="replace":
        a,b=int(t[1]),int(t[2])
        x=t[3]
        s=s[:a:]+x+s[b+1::]
