N,A,B=[int(i) for i in input().split(" ")]

Turn="Alice"
while True:
    if Turn=="Alice":
        if A==1 and B==2:
            print("Borys")
            break
        if A+1==B:
            A-=1
        else:
            A+=1
        Turn="Borys"
    else:
        if A==N-1 and B==N:
            print("Alice")
            break
        if A==B-1:
            B+=1
        else:
            B-=1
        Turn="Alice"
