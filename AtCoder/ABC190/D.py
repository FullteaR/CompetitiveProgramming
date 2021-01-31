def factoring(n):
    """
    This program factorize any number.
    This returns the dictionary of prime factors of the number.(if n=18=2*3**2, this returns {2:1,3:2})
        """
    if n == 0:
        return {0: 1}
    if n == 1:
        return {1: 1}

    # 今回のアルゴリズムについて
    # nが素数でない⇔nは√n以下の素因数を持つ⇒√n以下のすべての素数を列挙して、それでnを割っていってみる。
    #√n以下の素数をすべて書き出すために、エラトステネスの篩を使用する。t以下の素数をすべて列挙するためには√tまでの素数について調べれば十分なので、√nまでの素数を書き出すためには√√nまでの数について真面目に篩をかければいい。

    nOrigin = n
    n = n**0.5
    # n(=√input())以下の素数のリストをエラトステネスにより作成する
    # 素数の位置にはその数が、合成数の位置には-1が格納されているリストを作成
    # 0が格納されているのはまだ確認していない数。
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
import itertools
N=int(input())
f=factoring(2*N)
kata=[(0,)]
for key in f:
    kata=[iter for iter in itertools.product(kata,[j for j in range(f[key]+1)])]

primes=sorted(f.keys(), reverse=True)
facts=[]
for k in kata:
    fact = 1
    for p in primes:
        fact*=p**k[1]
        k=k[0]
    facts.append(fact)

facts=sorted(list(set(facts)))

retval=0
for f in facts:
    k=f-1
    if ((2*N)//f - k )%2==0:
        retval+=1
print(retval)
