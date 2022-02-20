N, X = [int(i) for i in input().split(" ")]
able = set([0])

for i in range(N):
    a, b = [int(j) for j in input().split(" ")]
    _able = set([j+a for j in able] + [j+b for j in able])
    able = _able

if X in able:
    print("Yes")
else:
    print("No")