import copy
N=int(input())
_s=[int(i) for i in input().split(" ")]

retval=0#A==N-1

#A%(A-B)!=0
#N>A>B>0
#N-1==k*(A-B)+A  (N-A-1)%(A-B)==0

def score(A,B):
    s=copy.copy(_s)
    place=0
    score=0
    for _ in range(N):
        score+=s[place]
        s[place]=-1*(10**100)
        place+=A
        if place==N-1:
            return score
        else:
            score+=s[place]
            s[place]=-1*(10**100)
            place-=B


for a in range(N-1):
    for b in range(1,a):
        if (N-a-1)%(a-b)!=0:
            continue
        retval=max(score(a,b),retval)
print(retval)
