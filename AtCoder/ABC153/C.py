N,K=[int(i) for i in input().split(" ")]
H=[int(i) for i in input().split(" ")]

H=sorted(H,reverse=True)
print(sum(H[K:]))
