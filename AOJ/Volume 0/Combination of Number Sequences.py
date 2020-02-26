import itertools
from tqdm import tqdm

print("{")
for n in tqdm(range(1,11)):
    retval=[0 for i in range(350)]
    for seq in itertools.permutations([j for j in range(10)],n):
        sum=0
        for i,num in enumerate(seq):
            sum+=(i+1)*num
        retval[sum]+=1

    print("    {",end="")
    print(",".join([str(i) for i in retval]),end="")
    print("},")
print("};")
