import numpy as np

c=[]
for i in range(4):
    c.append(input().split(" "))

c=np.asarray(c)
c=np.rot90(c, 2)

for _c in c:
    print(" ".join(_c))
