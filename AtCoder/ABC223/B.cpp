#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    vector<string> v;
    v.clear();
    string S;
    cin>>S;
    for(int i=0;i<S.size();i++){
        string _S = "";
        for(int j=0;j<S.size();j++){
            _S+=S[(j+i)%S.size()];
        }
        v.push_back(_S);
    }
    sort(v.begin(),v.end());
    cout<<v[0]<<endl;
    cout<<v[v.size()-1]<<endl;
    return 0;
}