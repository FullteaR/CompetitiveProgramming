N=int(input())

begins=['a']
while(len(begins[0])<N):
    _begins=[]
    for b in begins:
        n=len(set(b))
        for i in range(n+1):
            _begins.append(b+chr(ord('a')+i))
    begins=_begins

for b in sorted(begins):
    print(b)
