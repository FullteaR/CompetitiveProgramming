from functools import lru_cache

@lru_cache(maxsize=None)
def _pow(m,n):
    if n==0:
        return 1
    if n%2==0:
        return _pow(m,n//2)*_pow(m,n//2)
    else:
        return m*_pow(m,n-1)

def pow(m,n):
    num=_pow(m,n)
    string=""
    _num = num//_pow(10,68)
    if _num!=0:
        string+=str(_num)+"Mts"
    assert _num<10000
    num = num%_pow(10,68)

    _num = num//_pow(10,64)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Fks"
    num = num%_pow(10,64)

    _num = num//_pow(10,60)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Nyt"
    num = num%_pow(10,60)

    _num = num//_pow(10,56)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Asg"
    num = num%_pow(10,56)

    _num = num//_pow(10,52)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Ggs"
    num = num%_pow(10,52)

    _num = num//_pow(10,48)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Gok"
    num = num%_pow(10,48)

    _num = num//_pow(10,44)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Sai"
    num = num%_pow(10,44)

    _num = num//_pow(10,40)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Sei"
    num = num%_pow(10,40)

    _num = num//_pow(10,36)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Kan"
    num = num%_pow(10,36)

    _num = num//_pow(10,32)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Ko"
    num = num%_pow(10,32)

    _num = num//_pow(10,28)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Jou"
    num = num%_pow(10,28)

    _num = num//_pow(10,24)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Jo"
    num = num%_pow(10,24)

    _num = num//_pow(10,20)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Gai"
    num = num%_pow(10,20)

    _num = num//_pow(10,16)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Kei"
    num = num%_pow(10,16)

    _num = num//_pow(10,12)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Cho"
    num = num%_pow(10,12)

    _num = num//_pow(10,8)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Oku"
    num = num%_pow(10,8)

    _num = num//_pow(10,4)
    assert _num<10000
    if _num!=0:
        string+=str(_num)+"Man"
    num = num%_pow(10,4)

    if num!=0:
        string+=str(num)

    return string

while True:
    m,n=[int(i) for i in input().split(" ")]
    if n==0 and m==0:
        break
    print(pow(m,n))
