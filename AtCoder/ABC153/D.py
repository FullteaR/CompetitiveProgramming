from functools import lru_cache

@lru_cache()
def attack(H):
    if H==0:
        return 0
    elif H==1:
        return 1
    else:
        return 2*(attack(H//2))+1

H=int(input())
print(attack(H))
