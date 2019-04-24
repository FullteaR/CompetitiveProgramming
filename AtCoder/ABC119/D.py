import bisect
A,B,Q=[int(i) for i in input().split(" ")]

shrine=[-10**11]
for i in range(A):
    shrine.append(int(input()))
shrine.append(10**11)
temple=[-10**11]
for j in range(B):
    temple.append(int(input()))
temple.append(10**11)

def nearest_place(x,spot):
    if spot=="shrine":
        ind=bisect.bisect_left(shrine,x)-1

        left=shrine[ind]
        try:
            right=shrine[ind+1]
        except IndexError:
            right=shrine[ind]
        return left,right
    else:
                ind=bisect.bisect_left(temple,x)-1
                left=temple[ind]
                try:
                    right=temple[ind+1]
                except IndexError:
                    right=temple[ind]
                return left,right
ans=[]
for q in range(Q):
    x=int(input())
    retval=[]
    ls,rs=nearest_place(x,"shrine")
    lslt,lsrt=nearest_place(ls,"temple")
    rslt,rsrt=nearest_place(rs,"temple")
    lt,rt=nearest_place(x,"temple")
    ltls,ltrs=nearest_place(lt,"shrine")
    rtls,rtrs=nearest_place(rt,"shrine")
    retval.append(abs(x-ls)+abs(ls-lt))
    retval.append(abs(x-ls)+abs(ls-rt))
    retval.append(abs(x-rs)+abs(rs-lt))
    retval.append(abs(x-rs)+abs(rs-rt))
    retval.append(abs(x-lt)+abs(lt-ls))
    retval.append(abs(x-lt)+abs(lt-rs))
    retval.append(abs(x-rt)+abs(rt-ls))
    retval.append(abs(x-rt)+abs(rt-rs))
    ans.append(min(retval))

for a in ans:
    print(a)
