def check(N):
    if '7' in str(N):
        return False
    if '7' in oct(N):
        return False
    return True

N=int(input())

retval=0
for i in range(1,N+1):
    retval+=check(i)
print(retval)
