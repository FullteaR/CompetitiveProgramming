import sys

dream="dream"[::-1]
dreamer="dreamer"[::-1]
erase="erase"[::-1]
eraser="eraser"[::-1]

S=input()[::-1]

while S!="":
    if S[:5:]==dream:
        S=S[5::]
    elif S[:5:]==erase:
        S=S[5::]
    elif S[:7:]==dreamer:
        S=S[7::]
    elif S[:6:]==eraser:
        S=S[6::]
    else:
        print("NO")
        sys.exit()
print("YES")
