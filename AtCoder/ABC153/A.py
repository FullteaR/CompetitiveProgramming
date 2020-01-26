H,A=[int(i) for i in input().split(" ")]
if H%A==0:
    print(H//A)
else:
    print(H//A+1)
