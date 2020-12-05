import re
import sys

N=int(input())
T=input()

if N==1:
    if T=='0':
        print(10**10)
    else:
        print(2*(10**10))
    sys.exit()

if T[0]=='0':
    T='11'+T
elif T[0]=='1' and T[1]=='0':
    T='1'+T

if T[-1]=='0':
    pass
elif T[-1]=='1' and T[-2]=='1':
    T+='0'
elif T[-1]=='1' and T[-2]=='0':
    T+='10'

if re.search(r"^(110)*$",T):
    pass
else:
    print(0)
    sys.exit()

N=len(T)
repeat=N//3
assert N==repeat*3

print(10**10-repeat+1)
