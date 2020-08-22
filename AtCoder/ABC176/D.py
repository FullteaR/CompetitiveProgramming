INF = 10**10
H, W = [int(i) for i in input().split(" ")]
Ch, Cw = [int(i) + 1 for i in input().split(" ")]
Dh, Dw = [int(i) + 1 for i in input().split(" ")]
S = [[False for i in range(W + 4)], [False for i in range(W + 4)]]
for i in range(H):
    S.append([False, False] + [j == '.' for j in input()] + [False, False])
S += [[False for i in range(W + 4)], [False for i in range(W + 4)]]


def check(h, w, island_num):
    assert S[h][w]
    block[h][w] = island_num
    if S[h - 1][w] and block[h - 1][w] == -1:
        check(h - 1, w, island_num)
    if S[h + 1][w] and block[h + 1][w] == -1:
        check(h + 1, w, island_num)
    if S[h][w - 1] and block[h][w - 1] == -1:
        check(h, w - 1, island_num)
    if S[h][w + 1] and block[h][w + 1] == -1:
        check(h, w + 1, island_num)


block = []
for i in range(H + 4):
    block.append([-1 for j in range(W + 4)])

island_num = 0

for h in range(H + 4):
    for w in range(W + 4):
        if S[h][w] and block[h][w] == -1:
            check(h, w, island_num)
            island_num += 1


neighbor = {}
for island in range(island_num):
    neighbor[island] = set()


for h in range(2, H + 2):
    for w in range(2, W + 2):
        if block[h][w] != -1:
            for y in range(h - 2, h + 3):
                for x in range(w - 2, w + 3):
                    if block[y][x] != -1 and block[h][w] != block[y][x]:
                        neighbor[block[h][w]].add(block[y][x])


start = block[Ch][Cw]
goal = block[Dh][Dw]
assert start != -1
assert goal != -1


dist = [INF for i in range(island_num)]
dist[start] = 0

nexts = [start]
while True:
    _nexts = []
    for n in nexts:
        for neigh in neighbor[n]:
            assert neigh != -1
            if dist[neigh] > dist[n] + 1:
                _nexts.append(neigh)
                dist[neigh] = dist[n] + 1
    nexts = list(set(_nexts))
    if len(nexts) == 0:
        break

if dist[goal] == INF:
    print(-1)
else:
    print(dist[goal])
