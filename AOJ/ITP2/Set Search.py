S=set()

q=int(input())

for _ in range(q):
    query=[int(i) for i in input().split(" ")]
    if query[0]==0:
        S.add(query[1])
        print(len(S))
    else:
        if query[1] in S:
            print(1)
        else:
            print(0)
