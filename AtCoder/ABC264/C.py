import numpy as np
import itertools
import sys


H1,W1 = [int(i) for i in input().split(" ")]
A = []
for i in range(H1):
    A.append([int(j) for j in input().split(" ")])

H2,W2 = [int(i) for i in input().split(" ")]
B = []
for i in range(H2):
    B.append([int(j) for j in input().split(" ")])

A = np.asarray(A)
B = np.asarray(B)

delH = H1 - H2
delW = W1 - W2

for iter1 in itertools.combinations([int(i) for i in range(H1)], delH):
    for iter2 in itertools.combinations([int(i) for i in range(W1)], delW):
        mask = np.ones_like(A)
        for i in iter1:
            mask[i,:] = 0
        for i in iter2:
            mask[:,i] = 0
        if np.all(A[mask.astype(bool)].reshape(B.shape) == B):
            print("Yes")
            sys.exit(0)

print("No")

