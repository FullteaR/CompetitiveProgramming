from collections import Counter

def checkStraint(hand):
    hand=sorted(hand)
    if set(hand)==set([10,11,12,13,1]):
        return True
    for i in range(5):
        if hand[0]+i==hand[i]:
            continue
        else:
            return False
    return True

while True:
    try:
        hand=[int(i) for i in input().split(",")]
        hand=sorted(hand)
        c=Counter(hand)
        c=sorted(dict(c).items(),key=lambda w:w[1],reverse=True)
        if c[0][1]==4:
            print("four card")
            continue
        elif c[0][1]==3 and c[1][1]==2:
            print("full house")
            continue

        elif checkStraint(hand):
            print("straight")
            continue
        elif c[0][1]==3:
            print("three card")
            continue
        elif c[0][1]==2 and c[1][1]==2:
            print("two pair")
            continue
        elif c[0][1]==2:
            print("one pair")
            continue
        else:
            print("null")

    except EOFError:
        break
