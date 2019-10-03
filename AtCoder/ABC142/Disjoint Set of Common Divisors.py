def factoring(n):
    if n == 0:
        return {}
    if n == 1:
        return {}
    nOrigin = n
    n = n**0.5
    numlist = [0 for i in range(int(n) + 1)]
    numlist[0] = -1
    numlist[1] = -1

    #√√n以下の数について篩をかけていく
    t = 2
    while t < (n**0.5):
        if numlist[t] == 0:
            numlist[t] = t
            k = 2
            while t * k <= n:
                numlist[t * k] = -1
                k += 1
        t += 1

    #√√nより大きい数で、篩にかからなかった数は素数。
    while t <= n:
        if numlist[t] == 0:
            numlist[t] = t
        t += 1

    #√n以下の数で割っていく。
    result = {}
    for i in numlist:
        if i == -1:
            continue
        j = 0
        while nOrigin % i == 0:
            j += 1
            nOrigin = nOrigin / i
        if j == 0:
            continue
        else:
            result[i] = j

    if int(nOrigin) != 1:
        result[int(nOrigin)] = 1
    return result

def GCD(a, b):
    M = max(a, b)
    m = min(a, b)
    if m == 0:
        return M
    else:
        return GCD(m, M % m)


A,B=[int(i) for i in input().split(" ")]

fact=factoring(GCD(A, B))
print(len(fact)+1)
