import sys
S=input()

for i, s in enumerate(S):
    if i%2==0:
        if ord('a')<=ord(s) and ord(s) <= ord('z'):
            continue
        else:
            print("No")
            sys.exit()
    else:
        if ord('A')<=ord(s) and ord(s) <= ord('Z'):
            continue
        else:
            print("No")
            sys.exit()

print("Yes")
