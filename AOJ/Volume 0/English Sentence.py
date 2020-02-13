from collections import Counter
s=input()
s=s.lower()

s=s.split(" ")
long=sorted(s,key=lambda w:len(w),reverse=True)

freq=dict(Counter(s)).items()
freq=sorted(freq,key=lambda w:w[1],reverse=True)

print(freq[0][0],long[0])
