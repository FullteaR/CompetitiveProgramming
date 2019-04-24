import numpy as np
N,M=[int(i) for i in input().split(" ")]

G=np.zeros((N,N))
for i in range(N+M-1):
    A,B=[int(j)-1 for j in input().split(" ")]
    G[A][B]=1
root=(np.sum(G,axis=0)==0).argmax()

general=np.zeros(N,dtype=np.int)
print(G)
print(general)

def create_general(root,n):
    for i,j in enumerate(G[root]):
        if j==1:
            general[i]=max(n+1,general[i])
            create_general(i,n+1)
create_general(root,0)
print(general)

for i in range(N):
