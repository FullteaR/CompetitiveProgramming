N,K=[int(i) for i in input().split(" ")]
R,S,P=[int(i) for i in input().split(" ")]
T=input()


score=0
for i in range(K):
    hand=T[i::K]
    hand=hand.replace("pp","p")
    hand=hand.replace("rr","r")
    hand=hand.replace("ss","s")
    for h in hand:
        if h=="p":
            score+=S
        elif h=="r":
            score+=P
        else:
            score+=R
print(score)
