from collections import deque

N = int(input())
a = [int(i) for i in input().split(" ")]

stack = deque([])
count = 0
for ball in a:
    count+=1
    if len(stack)==0:
        stack.append([ball, 1])
    elif stack[-1][0]!=ball:
        stack.append([ball, 1])
    else:
        stack[-1][1]+=1
        if stack[-1][1]==ball:
            stack.pop()
            count-=ball
    print(count)
