K=int(input())
A,B=[int(i) for i in input().split(" ")]

for m in range(A,B+1):
    if m%K==0:
        print("OK")
        break
else:
    print("NG")
