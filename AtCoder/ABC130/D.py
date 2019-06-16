N,K=[int(i) for i in input().split(" ")]
a=[int(i) for i in input().split(" ")]




S=[0]
for _a in a:
    S.append(S[-1]+_a)

count=0
length=len(S)
for i in range(length):
    for j in range(i+1,length):
        if S[j]-S[i]>=K:
            count+=length-j
            break
        
print(count)
