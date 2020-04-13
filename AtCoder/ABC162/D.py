from collections import Counter

N=int(input())
S=input()

dup=0
RGB=set(('R','G','B'))

for width in range(N//2+10):
    for i in range(N):
        try:
            if set((S[i],S[i+width],S[i+width*2]))==RGB:
                dup+=1
        except IndexError:
            break

c=Counter(S)
retval=c['R']*c['G']*c['B']-dup
print(retval)
