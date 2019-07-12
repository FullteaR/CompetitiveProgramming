n = int(input())
l = [[] for i in range(n)]
retval=[10**10 for i in range(n)]



for i in range(n):
    _input = [int(j) - 1 for j in input().split(" ")]
    u = _input[0]
    k = _input[1] + 1
    node = sorted(_input[2::])
    if u in node:
        node.remove(u)
    l[u] = node

retval[0]=0
for step in range(n+1):
    for i ,d in enumerate(retval):
        if d==step:
            for node in l[i]:
                retval[node]=min(retval[node],step+1)

for i,d in enumerate(retval):
    if d==10**10:
        print(i+1,-1)
    else:
        print(i+1,d)
