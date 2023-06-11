#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
#include <cassert>
using namespace std;


class UnionFind { // without using rank(O(log n))
public:
    UnionFind(long long n);
    bool Same(long long x, long long y);
    void Union(long long x, long long y);

private:
    long long *parents;
    long long Root(long long x);
    long long n;
};

UnionFind::UnionFind(long long n) {
    parents = new long long[n];
    for (long long i = 0; i < n; i++) {
        parents[i] = i;
    }
    this->n = n;
}

long long UnionFind::Root(long long x) {
    if (parents[x] == x) {
        return x;
    }
    else {
        return parents[x] = Root(parents[x]);
    }
}

bool UnionFind::Same(long long x, long long y) {
    return Root(x) == Root(y);
}

void UnionFind::Union(long long x, long long y) {
    x = Root(x);
    y = Root(y);
    if (x == y)
        return;
    parents[x] = y;
    return;
}


long long pos_to_cell_num(pair<long long, long long> p, long long H, long long W);


int main(void) {
    long long H,W;
    long long Q;
    cin>>H>>W;
    H+=2;
    W+=2;
    bool** field = new bool*[H];
    for(long long h=0;h<H;h++) {
        field[h] = new bool[W];
        for(long long w=0;w<W;w++) {
            field[h][w] = false;
        }
    }
    long long max_num = pos_to_cell_num(make_pair(H-1,W-1),H,W);
    UnionFind* uf = new UnionFind(max_num);
    cin>>Q;
    for(long long q=0;q<Q;q++) {
        long long t;
        cin>>t;
        if(t==1){
            long long r,c;
            cin>>r>>c;
            field[r][c] = true;
            if(field[r-1][c]) {
                uf->Union(pos_to_cell_num(make_pair(r,c),H,W), pos_to_cell_num(make_pair(r-1,c),H,W));
            }
            if(field[r+1][c]) {
                uf->Union(pos_to_cell_num(make_pair(r,c),H,W), pos_to_cell_num(make_pair(r+1,c),H,W));
            }
            if(field[r][c-1]) {
                uf->Union(pos_to_cell_num(make_pair(r,c),H,W), pos_to_cell_num(make_pair(r,c-1),H,W));
            }
            if(field[r][c+1]) {
                uf->Union(pos_to_cell_num(make_pair(r,c),H,W), pos_to_cell_num(make_pair(r,c+1),H,W));
            }
        }
        else{
            assert(t==2);
            long long ra,ca,rb,cb;
            cin>>ra>>ca>>rb>>cb;
            long long na = pos_to_cell_num(make_pair(ra,ca),H,W);
            long long nb = pos_to_cell_num(make_pair(rb,cb),H,W);
            if(field[ra][ca] && field[rb][cb] && uf->Same(na, nb)) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }
    return 0;
};


long long pos_to_cell_num(pair<long long, long long> p, long long H, long long W) {
    long long r = p.first;
    long long c = p.second;
    return r*W+c;
};

