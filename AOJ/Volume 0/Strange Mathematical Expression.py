def calc(L):
    stack=[]
    for l in L:
        try:
            l=float(l)
            stack.append(l)
        except:
            b=stack.pop(-1)
            a=stack.pop(-1)
            if l=="+":
                stack.append(a+b)
            elif l=="-":
                stack.append(a-b)
            elif l=="*":
                stack.append(a*b)
            else:
                stack.append(a/b)
    return stack[0]



while True:
    try:
        s=input()
        print(calc(s.split(" ")))
    except EOFError:
        break
