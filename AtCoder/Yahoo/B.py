city=[0,0,0,0,0]
for i in range(3):
    a,b=[int(i) for i in input().split(" ")]
    city[a]+=1
    city[b]+=1

city.pop(0)
city=sorted(city)
if city==[1,1,2,2]:
    print("YES")
else:
    print("NO")
