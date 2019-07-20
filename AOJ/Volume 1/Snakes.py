import re

n=int(input())

def A(snake):
    r=re.match("^>\'(\=+)\#(\=+)\~$",snake)
    if r:
        if len(r.group(1))==len(r.group(2)):
            return True
    return False
def B(snake):
    r=re.match("^\>\^(Q=)+\~\~$",snake)
    if r:
        return True
    return False

for i in range(n):
    S=input()
    if A(S):
        print("A")
    elif B(S):
        print("B")
    else:
        print("NA")
