diamond=[]
path=[]
while True:
    try:
        s=[int(i) for i in input().split(",")]
        if(len(diamond)==0):
            diamond.append(s)
            path.append(s)
        elif(len(diamond[-1])<len(s)):
            diamond.append(s)
            _path=[path[-1][0]+s[0]]
            for i in range(len(s)-2):
                _path.append(max(path[-1][i],path[-1][i+1])+s[i+1])
            _path.append(path[-1][-1]+s[-1])
            path.append(_path)

        else:
            diamond.append(s)
            _path=[]
            for i in range(len(s)):
                _path.append(max(path[-1][i],path[-1][i+1])+s[i])
            path.append(_path)

            if len(s)==1:
                print(path[-1][0])
                diamond=[]
                path=[]
    except EOFError:
        break
