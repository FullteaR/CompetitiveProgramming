#include <iostream>
#include <set>
using namespace std;

int main(void){
    int N;
    cin>>N;
    set<int>* before = new set<int>[201];
    set<int>* after = new set<int>[201];
    for(int i=0;i<=200;i++){
        before[i].clear();
        after[i].clear();
    }
    for(int i=0;i<N;i++){
        int u,d;
        string status;
        cin>>u>>status>>d;
        d+=100;
        if(status=="lock"){
            before[u].insert(d);
            after[d].insert(u);
        }
        else{
            before[d].insert(u);
            after[u].insert(d);
        }
    }
    set<int> S;
    S.clear();
    for(int i=0;i<=200;i++){
        if(before[i].empty()){
            S.insert(i);
        }
    }
    while(!S.empty()){
        int s = *(S.begin());
        S.erase(s);
        for(int v:after[s]){
            before[v].erase(s);
            if(before[v].empty()){
                S.insert(v);
            }
        }
    }
    for(int i=0;i<=200;i++){
        if(!before[i].empty()){
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}