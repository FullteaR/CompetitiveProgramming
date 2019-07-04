N=int(input())
d=[int(i) for i in input().split(" ")]

d=sorted(d)
print(d[N//2]-d[N//2-1])
