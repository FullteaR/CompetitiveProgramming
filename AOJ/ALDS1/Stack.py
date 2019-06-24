S = input().split(" ")
stack=[]

while len(S)>1:
    for s in S:
        if s=="+":
            s1=stack.pop(-1)
            s2=stack.pop(-1)
            stack.append(s1+s2)
        elif s=="-":
            s1=stack.pop(-1)
            s2=stack.pop(-1)
            stack.append(s2-s1)
        elif s=="*":
            s1=stack.pop(-1)
            s2=stack.pop(-1)
            stack.append(s1*s2)
        else:
            stack.append(int(s))
    S=stack
print(S[0])
