a,b,c=[int(i) for i in input().split(" ")]

if c-a-b<0:
    print("No")
elif (a+b-c)**2>4*a*b:
    print("Yes")
else:
    print("No")
