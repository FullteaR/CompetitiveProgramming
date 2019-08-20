N = int(input())

v = [int(i) for i in input().split(" ")]

v = sorted(v)

while len(v) >= 2:
    v1 = v.pop(0)
    v2 = v.pop(0)
    v.append((v1 + v2) / 2)
    v = sorted(v)

print(v[0])
