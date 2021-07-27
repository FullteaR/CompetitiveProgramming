N=int(input())
A=[int(i) for i in input().split(" ")]
total=0
for a in A:
    if a<10:
        continue
    else:
        total+=a-10
print(total)