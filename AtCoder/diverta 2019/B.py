R, G, B, N = [int(i) for i in input().split(" ")]

count = 0
for r in range(N // R + 1):
    for g in range(N // G + 1):
        _b = N - r * R - g * G
        if _b < 0:
            break
        if _b % B == 0:
            count += 1
print(count)
