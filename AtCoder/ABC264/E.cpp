#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
#include <unordered_set>
using namespace std;

class UnionFind
{ // without using rank(O(log n))
public:
    UnionFind(long n);
    bool Same(long x, long y);
    void Union(long x, long y);
    long Count(long x);

private:
    long *parents;
    long Root(long x);
    long *counts;
    long n;
};

UnionFind::UnionFind(long n)
{
    parents = new long[n];
    counts = new long[n];
    for (long i = 0; i < n; i++)
    {
        parents[i] = i;
        counts[i] = 1;
    }
    this->n = n;
}

long UnionFind::Root(long x)
{
    if (parents[x] == x)
    {
        return x;
    }
    else
    {
        return parents[x] = Root(parents[x]);
    }
}

bool UnionFind::Same(long x, long y)
{
    return Root(x) == Root(y);
}

void UnionFind::Union(long x, long y)
{
    x = Root(x);
    y = Root(y);
    if (x == y)
        return;
    parents[x] = y;
    long total = counts[x]+counts[y];
    counts[x] = total;
    counts[y] = total;
    return;
}

long UnionFind::Count(long x) {
    return counts[Root(x)];
}


int main(void){
    long N,M,E;
    cin>>N>>M>>E;
    vector<pair<long, long> >v;
    v.clear();
    for(long i =0;i<E;i++){
        long U,V;
        cin>>U>>V;
        v.push_back(make_pair(U-1,V-1));
    }
    vector<long> event;
    unordered_set<long> event_set;
    event.clear();
    event_set.clear();
    long Q;
    cin>>Q;
    for(long i=0;i<Q;i++){
        long X;
        cin>>X;
        event.push_back(X-1);
        event_set.insert(X-1);
    }
    reverse(event.begin(), event.end());

    UnionFind uf(N+M);
    for(long i=N;i<N+M;i++){
        uf.Union(i, N);
    }

    for(long i=0;i<E;i++){
        if(event_set.find(i)==event_set.end()){
            uf.Union(v[i].first, v[i].second);
        }
    }
    vector<long> retval;
    retval.clear();
    for(long i=0;i<Q;i++){
        retval.push_back(uf.Count(N)-M);
        uf.Union(v[event[i]].first, v[event[i]].second);
    }
    reverse(retval.begin(), retval.end());
    for(long r:retval){
        cout<<r<<endl;
    }
}