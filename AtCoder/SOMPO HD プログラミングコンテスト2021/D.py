import sys
def Base_n_to_10(X,n):
    out = 0
    for i in range(1,len(str(X))+1):
        out += int(X[-i])*(n**(i-1))
    return out#int out


X=input()
M=int(input())

if len(X)==1:
    if int(X)<=M:
        print(1)
    else:
        print(0)
    sys.exit()

d = max([int(i) for i in X])
low = d+1
high=10**20
assert Base_n_to_10(X,high)>M
while high-low>10 and high>=low:
    mid=(low+high)//2
    if Base_n_to_10(X,mid)<=M:
        low = mid
    else:
        high = mid
#assert Base_n_to_10(X,low)<=M
#assert Base_n_to_10(X,high)>M
retval=0
for i in range(low, high+1):
    if Base_n_to_10(X,i)>M:
        retval = i-d-1
        break

print(max(retval,0))
