def game(A,N):
    for A_i in A:
        N-=N%A_i
        if N<2:
            return False
    if N==2:
        return True
    else:
        return False

K=int(input())
A=[int(i) for i in input().split(" ")]



minimum=-1
maximum=-1
for i in range(max(A),sum(A)-K+3):
    if game(A,i):
        maximum=i
        if minimum==-1:
            minimum=i

if minimum!=-1:
    print("{0} {1}".format(minimum,maximum))
else:
    print("-1")
