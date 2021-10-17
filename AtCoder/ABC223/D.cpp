#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void){
    vector<int> L;
    L.clear();
    int N,M;
    cin>>N>>M;
    set<int> * before = new set<int>[N];
    set<int> * after = new set<int>[N];
    for(int i=0;i<N;i++){
        before[i].clear();
        after[i].clear();
    }
    for(int i=0;i<M;i++){
        int A,B;
        cin>>A>>B;
        A--;
        B--;
        before[B].insert(A);
        after[A].insert(B);
    }
    set<int> S;
    S.clear();
    for(int i=0;i<N;i++){
        if(before[i].empty()){
            S.insert(i);
        }
    }
    while(!S.empty()){
        int n = *(S.begin());
        S.erase(n);
        L.push_back(n);
        for(int n2:after[n]){
            before[n2].erase(n);
            if(before[n2].empty()){
                S.insert(n2);
            }
        }
    }
    for(int i=0;i<N;i++){
        if(!before[i].empty()){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<N;i++){
        cout<<L[i]+1;
        if(i<N-1){
            cout<<" ";
        }
        else{
            cout<<endl;
        }
    }
    return 0;
}