from itertools import combinations

N = int(input())
persons = []
for i in range(N):
    persons.append([int(j) for j in input().split(" ")])

def isPossible(K, _persons):
    persons = set()
    for p in _persons:
        persons.add(tuple([i>=K for i in p]))

    for iter in combinations(persons, 1):
        check = [iter[0][i] for i in range(5)]
        if check == [True,True,True,True,True]:
            return True
    
    for iter in combinations(persons, 2):
        check = [iter[0][i] or iter[1][i] for i in range(5)]
        if check == [True,True,True,True,True]:
            return True

    for iter in combinations(persons, 3):
        check = [iter[0][i] or iter[1][i] or iter[2][i] for i in range(5)]
        if check == [True,True,True,True,True]:
            return True
    return False

m = 0
M = 10**9+1
while M-m>1:
    mid = (M+m)//2
    if isPossible(mid, persons):
        m = mid
    else:
        M = mid

if isPossible(M, persons):
    print(M)
else:
    print(m)