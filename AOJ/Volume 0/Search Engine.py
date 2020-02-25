while True:
    try:
        s=input()
        s=s.replace(","," ")
        s=s.replace("."," ")
        s=s.split(" ")
        ans=[]
        for w in s:
            if len(w)>=3 and len(w)<=6:
                ans.append(w)
        print(" ".join(ans))
    except EOFError:
        break
