n = int(input())
S = [int(i) for i in input().split(" ")]
q = int(input())
T = [int(i) for i in input().split(" ")]

print(len(set(S) & set(T)))
