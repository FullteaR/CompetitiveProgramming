H,W=[int(i) for i in input().split(" ")]
h,w=[int(i) for i in input().split(" ")]

print(H*W-h*W-H*w+h*w)
