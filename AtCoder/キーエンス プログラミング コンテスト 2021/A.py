N=int(input())
a=[int(i) for i in input().split(" ")]
b=[int(i) for i in input().split(" ")]


a_max=[0]
for i in range(1,N):
    if a[a_max[i-1]]<a[i]:
        a_max.append(i)
    else:
        a_max.append(a_max[i-1])
p=0
q=0
print(a[0]*b[0])
for i in range(1,N):
    if a[p]*b[q]<b[i]*a[a_max[i]]:
        q=i
        p=a_max[i]

    print(a[p]*b[q])
