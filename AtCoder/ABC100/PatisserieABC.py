N,M=[int(i) for i in input().split(" ")]
cake1=[]
cake2=[]
cake3=[]
cake4=[]
cake5=[]
cake6=[]
cake7=[]
cake8=[]
for i in range(N):
    x,y,z=[int(j) for j in input().split(" ")]
    cake1.append(x+y+z)
    cake2.append(-x+y+z)
    cake3.append(x-y+z)
    cake4.append(x+y-z)
    cake5.append(-x-y+z)
    cake6.append(-x+y-z)
    cake7.append(x-y-z)
    cake8.append(-x-y-z)

cake1=sorted(cake1)[::-1]
cake2=sorted(cake2)[::-1]
cake3=sorted(cake3)[::-1]
cake4=sorted(cake4)[::-1]
cake5=sorted(cake5)[::-1]
cake6=sorted(cake6)[::-1]
cake7=sorted(cake7)[::-1]
cake8=sorted(cake8)[::-1]
print(max(sum(cake1[:M:]),sum(cake2[:M:]),sum(cake3[:M:]),sum(cake4[:M:]),sum(cake5[:M:]),sum(cake6[:M:]),sum(cake7[:M:]),sum(cake8[:M:])))
