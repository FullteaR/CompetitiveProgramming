N,M=[int(i) for i in input().split(" ")]

retval=0
retval+=(N-1)*N//2
retval+=(M-1)*M//2
print(retval)
