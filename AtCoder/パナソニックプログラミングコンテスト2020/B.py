import sys
H,W=[int(i) for i in input().split(" ")]

if H==1 or W==1:
    print(1)
    sys.exit()

print((H*W+1)//2)
