#include <iostream>
using namespace std;

int main(void) {
    int N,K;
    cin>>N>>K;
    string S;
    cin>>S;
    string T = "";
    int invite = 0;
    for(int i=0;i<S.size();i++) {
        if(S[i]=='x' || invite>=K) {
            T+='x';
        }
        else{
            T+='o';
            invite++;
        }
    }
    cout<<T<<endl;
    return 0;
}