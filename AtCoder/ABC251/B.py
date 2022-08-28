import itertools
N,W=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]
retval = set()

for iter in itertools.combinations(A,1):
    s = sum(iter)
    if s<=W:
        retval.add(s)

for iter in itertools.combinations(A,2):
    s = sum(iter)
    if s<=W:
        retval.add(s)

for iter in itertools.combinations(A,3):
    s = sum(iter)
    if s<=W:
        retval.add(s)

print(len(retval))