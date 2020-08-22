import itertools

H, W, M = [int(i) for i in input().split(" ")]

target = []
for i in range(M):
    target.append(tuple([int(j) - 1 for j in input().split(" ")]))

target = set(target)

tate = [0 for i in range(H)]
yoko = [0 for i in range(W)]
for t in target:
    tate[t[0]] += 1
    yoko[t[1]] += 1


tate_max = max(tate)
yoko_max = max(yoko)

tate_max_ind = []
for i, t in enumerate(tate):
    if t == tate_max:
        tate_max_ind.append(i)

yoko_max_ind = []
for i, y in enumerate(yoko):
    if y == yoko_max:
        yoko_max_ind.append(i)

for iter in itertools.product(tate_max_ind, yoko_max_ind):
    if (iter in target) == False:
        print(tate_max + yoko_max)
        break

else:
    print(tate_max + yoko_max - 1)
