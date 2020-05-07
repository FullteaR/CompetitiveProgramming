N,M=[int(i) for i in input().split(" ")]
H=[int(i) for i in input().split(" ")]


tenboudai=[True for i in range(N)]

for _ in range(M):
    A,B=[int(i) for i in input().split(" ")]
    A-=1
    B-=1
    if H[A]>=H[B]:
        tenboudai[B]=False
    if H[A]<=H[B]:
        tenboudai[A]=False


print(sum(tenboudai))
