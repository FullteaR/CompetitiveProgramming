import sys
while True:
    H, W = [int(i) for i in input().split(" ")]
    if H == 0 and W == 0:
        break
    Tiles = []
    for i in range(H):
        Tiles.append(input())

    step = 0

    x = 0
    y = 0
    while True:

        if Tiles[y][x] == ">":
            x += 1
        elif Tiles[y][x] == "<":
            x -= 1
        elif Tiles[y][x] == "^":
            y -= 1
        elif Tiles[y][x] == "v":
            y += 1
        step += 1

        if Tiles[y][x] == ".":
            print(x, y)
            break
        if step > H * W + 5:
            print("LOOP")
            break
