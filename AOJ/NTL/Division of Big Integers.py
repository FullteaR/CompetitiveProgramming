A,B=[int(i) for i in input().split(" ")]
if A*B>=0:
    print(A//B)
else:
    if B*(A//B)==A:
        print(A//B)
    else:
        print(A//B+1)
