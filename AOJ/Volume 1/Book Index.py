index={}
while True:
    try:
        word,page=input().split(" ")
        page=int(page)
        tmp=index.get(word,[])
        tmp.append(page)
        index[word]=tmp

    except EOFError:
        break


index=sorted(index.items())
for object in index:
    print(object[0])
    print(" ".join([str(i) for i in sorted(object[1])]))
