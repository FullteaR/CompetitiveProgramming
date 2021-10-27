#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define INF 1000000010000

void dijkstra(unordered_map<string, unordered_set<string> > * v, string s, unordered_map<string, long long>* retval);

int main(void){
    string s="012345678";
    unordered_map<string, unordered_set<string> > v;
    unordered_map<string, long long> retval;
    long long i=0;
    int M;
    cin>>M;
    pair<int, int> *edges = new pair<int, int>[M];
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        edges[i] = make_pair(u,v);
    }
    do{
        v[s].clear();
        for(i=0;i<M;i++){
            pair<int,int> edge = edges[i];
            if(s[edge.first]=='0' or s[edge.second]=='0'){
                string _s=s;
                char tmp = _s[edge.first];
                _s[edge.first] = _s[edge.second];
                _s[edge.second] = tmp;
                v[s].insert(_s);
            }
        }
    }while(next_permutation(s.begin(), s.end()));
    string p = "000000000";
    for(int i=1;i<9;i++){
        int _p;
        cin>>_p;
        p[_p-1] = (char)(i+'0');
    }
    dijkstra(&v, p, &retval);
    long long score = retval["123456780"];
    if(score==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<score<<endl;
    }
}

/*
   入力
   v: 隣接要素のunordered_setを持つmap。v[i]は頂点iから行くことができる頂点を集めたunordered_set。
   s: スタート
   retval: 各頂点のスタートからの最短距離が格納されるmap。
 */
void dijkstra(unordered_map<string, unordered_set<string> > * v, string s, unordered_map<string, long long>* retval){
        retval->clear();
        for(auto iter = v->begin(); iter != v->end(); iter++) {
                (*retval)[iter->first]=INF;
        }
        (*retval)[s]=0;
        unordered_set<string> updated, next;
        updated.clear();
        updated.insert(s);
        while(!updated.empty()) {
                next.clear();
                for(auto iter=updated.begin(); iter!=updated.end(); iter++) {
                        for(auto iter2=(*v)[*iter].begin(); iter2!=(*v)[*iter].end(); iter2++) {
                                if((*retval)[*iter2]>(*retval)[*iter]+1) {
                                        (*retval)[*iter2]=(*retval)[*iter]+1;
                                        next.insert(*iter2);
                                }
                        }
                }
                updated.swap(next);
        }
}