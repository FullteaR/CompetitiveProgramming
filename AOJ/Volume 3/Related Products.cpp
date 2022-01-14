#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <cassert>
using namespace std;

int main(void){
    int N,F;
    cin>>N>>F;
    map<pair<string, string>, int> d;
    assert(d.empty());
    for(int i=0;i<N;i++){
        int M;
        cin>>M;
        set<string> items;
        items.clear();
        for(int j=0;j<M;j++){
            string item;
            cin>>item;
            items.insert(item);
        }
        for(string item1 : items){
            for(string item2: items){
                if(item1==item2){
                    continue;
                }
                pair<string, string> p = make_pair(min(item1, item2), max(item1, item2));
                if(d.find(p)==d.end()){
                    d[p]=1;
                }
                else{
                    d[p]+=1;
                }
            }
        }
    }
    int total_count = 0;
    for(auto p: d){
        pair<string, string> key = p.first;
        int value = p.second;
        if(value>=2*F){
            total_count++;
        }
    }
    cout<<total_count<<endl;
    for(auto p: d){
        pair<string, string> key = p.first;
        int value = p.second;
        if(value>=2*F){
            cout<<key.first<<" "<<key.second<<endl;
        }
    }
    return 0;
}