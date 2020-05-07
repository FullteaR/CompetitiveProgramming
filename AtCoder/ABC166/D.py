X=int(input())


for A in range(120):
    B5=abs(A**5-X)
    Bfugou=A**5>X
    B=B5**0.2
    B=int(B)
    if Bfugou==False:
        B=-B
    if A**5-B**5==X:
        print(A,B)
        break
    A+=1
