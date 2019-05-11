from functools import lru_cache
N = int(input())
a = tuple([int(i) for i in input().split(" ")])


def beauty(l):
    retval = 0
    for i in l:
        retval = retval ^ i
    return retval


@lru_cache()
def is_able(l, k):
    retval = 0
    if beauty(l) == k:
        retval += 1
    for i in range(1, len(l)):
        if beauty(l[:i:]) != k:
            continue
        else:
            retval += is_able(l[i::], k)
    return retval


retval = 0
for i in range(21):
    retval += is_able(a, i)
print(retval % (10**9 + 7))
