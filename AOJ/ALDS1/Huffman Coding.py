from collections import Counter

S=input()
freq=sorted(list(dict(Counter(S)).items()),key=lambda w:w[1])
length={chr(ord('a')+i):0 for i in range(26)}
while len(freq)>1:
    minimum1=freq.pop(0)
    minimum2=freq.pop(0)
    for c in minimum1[0]+minimum2[0]:
        length[c]=length[c]+1
    freq.append((minimum1[0]+minimum2[0],minimum1[1]+minimum2[1]))
    freq=sorted(freq,key=lambda w:w[1])

retval=0
for s in S:
    retval+=max(length[s],1)
print(retval)
