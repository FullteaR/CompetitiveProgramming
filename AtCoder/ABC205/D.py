import bisect

N,Q=[int(i) for i in input().split(" ")]
A = [int(i) for i in input().split(" ")]
A = sorted(A)
keys = []
key_map = {}


for _ in range(Q):
    K = int(input())
    index = bisect.bisect_right(keys,K)>0
    if index>0:
        ans = key_map[keys[index-1]]
    else:
        ans = K
    exist = bisect.bisect_right(A, ans)
    while ans-exist!=K:
        ans+=(K-(ans-exist))
        exist = bisect.bisect_right(A, ans)
    print(ans)
    bisect.insort(keys,K)
    key_map[K] = ans