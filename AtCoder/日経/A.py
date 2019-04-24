N,A,B=[int(i) for i in input().split(" ")]
maximum=min(A,B)
minimum=max(A+B-N,0)
print(maximum,minimum)
