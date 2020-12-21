T=int(input())

class LDE:
    #初期化
    def __init__(self,a,b,c):
        self.a,self.b,self.c=a,b,c
        self.m,self.x0,self.y0=0,[0],[0]
        #解が存在するか
        self.check=True
        g=gcd(self.a,self.b)
        if c%g!=0:
            self.check=False
        else:
            #ax+by=gの特殊解を求める
            self.extgcd(self.a,self.b,self.x0,self.y0)
            #ax+by=cの特殊解を求める
            self.x0=self.x0[0]*c//g
            self.y0=self.y0[0]*c//g
            #一般解を求めるために
            self.a//=g
            self.b//=g

    #拡張ユークリッドの互除法
    #返り値:aとbの最大公約数
    def extgcd(self,a,b,x,y):
        if b==0:
            x[0],y[0]=1,0
            return a
        d=self.extgcd(b,a%b,y,x)
        y[0]-=(a//b)*x[0]
        return d

    #パラメータmの更新(書き換え)
    def m_update(self,m):
        self.x0+=(m-self.m)*self.b
        self.y0-=(m-self.m)*self.a
        self.m=m

def gcd(a,b):
    if min(a,b)==0:
        return max(a,b)
    else:
        return gcd(min(a,b), max(a,b)%min(a,b))

def solve(N,S,K):
    d = gcd(N,K)
    if S%d!=0:
        return -1

    lde = LDE(N,K,S)
    N=N//d
    K=K//d
    S=S//d
    return (-1*lde.y0)%N

for _ in range(T):
    N,S,K=[int(i) for i in input().split(" ")]
    print(solve(N,S,K))
