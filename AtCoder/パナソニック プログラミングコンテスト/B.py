import numpy as np

H,W=[int(i) for i in input().split(" ")]

A=[]
for i in range(H):
    A.append([int(j) for j in input().split(" ")])

A=np.asarray(A)

print(np.sum(A)-np.min(A)*H*W)
