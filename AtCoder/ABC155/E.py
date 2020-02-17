from functools import lru_cache
import matplotlib.pyplot as plt
N=int(input())

@lru_cache()
def _pay(N):
    if N<5:
        return N
    n=N%10
    if n==5:
        return 5+min(_pay(N//10),_pay(N//10+1))
    elif n<5:
        return n+_pay(N//10)
    else:
        return 10-n+_pay(1+N//10)




for i in range(1000):
    print(i,_pay(i))
