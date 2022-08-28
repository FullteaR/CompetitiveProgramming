import itertools
from tqdm.auto import tqdm

weights = set([3,6, 10, 4])

for w in tqdm(range(1,W+1)):
    flag = True
    if w in weights:
        flag = False
        continue
    for weight in weights:
        if w-weight<=weight:
            continue
        elif w-weight in weights:
            flag = False
            break
    if flag == False:
        continue

    for iter in itertools.combinations(weights, 2):
        weight, weight2 = iter
        if w-(weight+weight2) <=weight or w-(weight+weight2)<=weight2:
            continue 
        elif w-(weight+weight2) in weights:
            flag = False
            break
    if flag:
        weights.add(w)

print(sorted(list(weights)))