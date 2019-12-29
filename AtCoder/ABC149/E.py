import heapq
import itertools

N,M=[int(i) for i in input().split(" ")]

A=[int(i) for i in input().split(" ")]
A=sorted(A,reverse=True)
A=A[:M//2+10]
scores=[]
heapq.heapify(scores)
for pair in itertools.product(A, repeat=2):
    score=(pair[0]+pair[1])*(-1)
    heapq.heappush(scores,score)


retval=0
for i in range(M):
    retval+=heapq.heappop(scores)

print(retval*(-1))
