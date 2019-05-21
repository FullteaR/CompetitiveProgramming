import sys

N = int(input())
_A = [int(i) for i in input().split(" ")]+[0]
A = [0]
for _a in _A:
    if A[-1] != _a:
        A.append(_a)



kouho = sorted(list(set(A)))

N = len(A)
mountain = []
valley = []
for i in range(1, N - 1):
    if A[i - 1] > A[i] and A[i] < A[i + 1]:
        valley.append(A[i])
    elif A[i - 1] < A[i] and A[i] > A[i + 1]:
        mountain.append(A[i])

island=0
retval=island


if kouho==[0]:
    print(0)
    sys.exit()

for i in kouho:
    if i in valley:
        island+=valley.count(i)
        retval=max(retval,island)
    if i in mountain:
        island-=mountain.count(i)
    print(i,island)

print(retval)
