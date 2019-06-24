process = []
n, q = [int(i) for i in input().split(" ")]
for i in range(n):
    name, time = input().split(" ")
    time = int(time)
    process.append([name, time])

time = 0
while len(process) > 0:
    p = process.pop(0)
    if p[1] <= q:
        time += p[1]
        print(p[0], time)
    else:
        p[1] -= q
        time += q
        process.append(p)
