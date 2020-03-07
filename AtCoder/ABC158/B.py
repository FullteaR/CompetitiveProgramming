N,A,B=[int(i) for i in input().split(" ")]
ball=(N//(A+B))*A
if N%(A+B)>A:
    ball+=A
else:
    ball+=N%(A+B)

print(ball)
