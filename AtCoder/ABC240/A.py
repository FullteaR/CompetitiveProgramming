a,b = [int(i) for i in input().split(" ")]
if abs(a-b)==1:
    print("Yes")
elif abs(a-b)==9:
    print("Yes")
else:
    print("No")