import sys

N, A, B = [int(i) for i in input().split(" ")]




def whetherConnect(i,j):
    score=0
    for i in bin(i^j)[2::]:
        score+=int(i)
    return score==1


def deepSearch(history,visitedFlag,visitedCount):
    lastVisited=history[-1]
    if visitedCount==2**N-1:
        return whetherConnect(lastVisited,B)

    visitedFlag[lastVisited]=1
    visitedCount+=1
    for i ,flag in enumerate(visitedFlag):




history=[A]
visitedFlag=[0 for i in range(2**N)]
visitedFlag[A]=1


for visitedCount in range(1,2**N):
    for i,flag in enumerate(visitedFlag):
        if flag==1:
            continue
        if i==B:
            if visitedCount==2**N-1:
                history.append(B)
                print("YES")
                print(" ".join([str(i) for i in history]))
                sys.exit()
        if whetherConnect(history[-1],i):
            history.append(i)
            visitedFlag[i]=1
            break

print("NO")
