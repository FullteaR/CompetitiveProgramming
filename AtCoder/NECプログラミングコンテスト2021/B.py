A, B = input().split(" ")
Len = max(len(A), len(B))
A = A.zfill(Len)
B = B.zfill(Len)

for a, b in zip(A,B):
    if int(a)+int(b)>=10:
        print("Hard")
        break
else:
    print("Easy")