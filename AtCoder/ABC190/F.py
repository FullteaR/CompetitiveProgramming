import bisect
N=int(input())
a=[int(i) for i in input().split(" ")]
exist=[]
trans=0
for _a in a:
    index=bisect.bisect_left(exist,_a)
    trans+=len(exist)-index
    exist.insert(index,_a)

print(trans)
for _a in a[:-1]:
    trans+=N-1-2*_a
    print(trans)
