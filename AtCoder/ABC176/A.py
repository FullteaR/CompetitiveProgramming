N,X,T=[int(i) for i in input().split(" ")]

if N%X==0:
    repeat=N//X
else:
    repeat=N//X+1

print(T*repeat)
