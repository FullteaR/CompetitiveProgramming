#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
class UnionFind {
public:
UnionFind(long n);
bool Same(long x, long y);
void Union(long x, long y);
long Root(long x);
private:
long * parents;
};

UnionFind::UnionFind(long n){
        parents = new long[n];
        for(long i=0; i<n; i++) {
                parents[i]=i;
        }
}

long UnionFind::Root(long x){
        if(parents[x]==x) {
                return x;
        }
        else{
                return parents[x]=Root(parents[x]);
        }
}

bool UnionFind::Same(long x, long y){
        return Root(x)==Root(y);
}

void UnionFind::Union(long x, long y){
        x = Root(x);
        y = Root(y);
        if(x==y) return;
        parents[x]=y;
        return;
}



int main(void){
    long N,M;
    cin>>N>>M;
    map<long, set<long> > neighbors;
    for(long i=0;i<N;i++){
        neighbors[i].clear();
    }
    for(long i=0;i<M;i++){
        long A,B;
        cin>>A>>B;
        A--;
        B--;
        neighbors[min(A,B)].insert(max(A,B));
    }
    long size = N;
    UnionFind uf(N);
    vector<long> retval;
    for(long i=N-1;i>=0;i--){
        retval.push_back(size-i-1);
        set<long> neighbor = neighbors[i];
        set<long> roots;
        roots.clear();
        roots.insert(uf.Root(i));
        for(long n : neighbor){
            roots.insert(uf.Root(n));
            uf.Union(n, i);
        }
        size-=(roots.size()-1);
    }
    for(long i=retval.size()-1;i>=0;i--){
        cout<<retval[i]<<endl;
    }

    return 0;
}