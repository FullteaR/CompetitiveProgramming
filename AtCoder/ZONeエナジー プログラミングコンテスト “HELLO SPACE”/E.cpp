#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

//dijkstra search
/*
   入力
   v: 隣接要素のsetを持つmap。v[i]は頂点iから行くことができる頂点を集めたset。
   mp: 辺の重みを参照 mp[make_pair(i,j)]で辺i->jの重みを取得できる。
   s: スタート
   retval: 各頂点のスタートからの最短距離が格納されるmap。
 */
void dijkstra(map<long long, set<long long> > * v, map<pair<long long, long long>,long long> * mp, long long s, map<long long, long long>* retval){
        retval->clear();
        for(auto iter = v->begin(); iter != v->end(); iter++) {
                (*retval)[iter->first]=INF;
        }
        (*retval)[s]=0;
        set<long long> updated, next;
        updated.clear();
        updated.insert(s);
        while(!updated.empty()) {
                next.clear();
                for(auto iter=updated.begin(); iter!=updated.end(); iter++) {
                        for(auto iter2=(*v)[*iter].begin(); iter2!=(*v)[*iter].end(); iter2++) {
                                long long weight=(*mp)[make_pair(*iter,*iter2)];
                                if((*retval)[*iter2]>(*retval)[*iter]+weight) {
                                        (*retval)[*iter2]=(*retval)[*iter]+weight;
                                        next.insert(*iter2);
                                }
                        }
                }
                updated.swap(next);
        }
}

long long convert(long long r, long long c, long long C, bool virtual){
    return 2*(r*C+c)+(long long)virtual;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long R,C;
    cin>>R>>C;
    map<long long, set<long long> > v;
    map<pair<long long, long long>,long long> mp;
    map<long long, long long> retval;
    for(long long r=0;r<R;r++){
        for(long long c=0;c<C-1;c++){
            long long A;
            cin>>A;
            mp[make_pair(convert(r,c,C,false))]
        }
    }
}
