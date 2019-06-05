import sys

while True:
    try:
        s=input()
        ans=s.split("=")[1]
        a,b=s.split("=")[0].split("+")
        for X in range(10):
            _a=a.replace("X",str(X))
            if str(int(_a))!=_a:
                continue
            _b=b.replace("X",str(X))
            if str(int(_b))!=_b:
                continue
            _ans=ans.replace("X",str(X))
            if str(int(_ans))!=_ans:
                continue
            if int(_a)+int(_b)==int(_ans):
                print(X)
                break
        else:
            print("NA")

    except EOFError:
        sys.exit(0)
