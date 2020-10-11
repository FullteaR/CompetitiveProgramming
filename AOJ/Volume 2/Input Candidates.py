from collections import Counter

while True:
    n=int(input())
    if n==0:
        break

    words=[]
    for i in range(n):
        words+=input().split(" ")

    k=input()

    c=Counter(words)
    candidates=[(word,c[word]) for word in c if word[0]==k]
    candidates = sorted(candidates, key=lambda w:(-1*w[1],w[0]))[:5]
    if len(candidates)==0:
        print("NA")
    else:
        print(" ".join([cand[0] for cand in candidates]))
