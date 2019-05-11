N = int(input())
yakusuu = []

for i in range(1, int(N**0.5) + 1):
    if N % i == 0:
        yakusuu.append(i - 1)
        yakusuu.append(N // i - 1)
retval = 0
for y in yakusuu:
    if y == 0:
        continue
    if N // y == N % y:
        retval += y

print(retval)
