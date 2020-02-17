N=int(input())
A=[int(i) for i in input().split(" ")]

approve=True

for a in A:
    if a%2==1:
        continue
    if a%3!=0 and a%5!=0:
        approve=False

if approve:
    print("APPROVED")
else:
    print("DENIED")
