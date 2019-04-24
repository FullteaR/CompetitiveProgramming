from tqdm import tqdm

def rev(n):
    return int(str(n)[::-1])

def sousa(x,y):
    if x<y:
        x=rev(x)
    else:
        y=rev(y)

    if x<y:
        y=max(x,y)-min(x,y)
    else:
        x=max(x,y)-min(x,y)

    return x,y


fd=open("D.txt","w")

count=0
N,M=[int(i) for i in input().split(" ")]
for _x in tqdm(range(1,N+1)):

    for _y in range(1,M+1):
        log=[]
        x=_x
        y=_y
        flag =False
        while x>0 and y>0:
            x,y=sousa(x,y)
            if (x,y) in log:
                fd.write("1")
                flag=True
                count+=1
                break
            else:
                log.append((x,y))
        if flag==False:
            fd.write("0")
    fd.write("\n")

print(count)
