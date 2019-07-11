n = int(input())
l = [[] for i in range(n)]


class V:
    def __init__(self, node):
        self.d = -1
        self.f = -1
        self.node = node


for i in range(n):
    _input = [int(j) - 1 for j in input().split(" ")]
    u = _input[0]
    k = _input[1] + 1
    node = sorted(_input[2::])
    if u in node:
        node.remove(u)
    l[u] = V(node)

time = 1


def DFS(i):
    global time
    if l[i].d == -1:
        l[i].d = time
    time += 1
    for n in l[i].node:
        if l[n].d == -1:
            DFS(n)
            time+=1
    if l[i].f == -1:
        l[i].f = time
    return


for i in range(n):
    if l[i].d == -1:
        DFS(i)
        time+=1

for i, v in enumerate(l):
    print(i + 1, v.d, v.f)
