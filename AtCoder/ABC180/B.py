N=int(input())
x=[abs(int(i)) for i in input().split(" ")]

print(sum(x))
print(sum([i**2 for i in x])**0.5)
print(max(x))
