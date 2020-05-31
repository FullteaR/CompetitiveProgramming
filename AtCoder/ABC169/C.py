A,B=input().split(" ")
A=int(A)
B=float(B)
B=int(B*100)
retval=A*B
print(str(retval)[:-2].zfill(1))
