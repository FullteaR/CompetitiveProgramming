#include <iostream>
using namespace std;

long search(string s, char c);

int main(void){
    long N,K;
    cin>>N>>K;
    string S;
    cin>>S;
    string T = "";
    while(K>0){
        for(long i=0;i<26;i++){
            char cand = 'a'+i;
            long index = search(S, cand);
            if(index!=-1 and index+K-1<(long)S.size()){
                T+=cand;
                K--;
                S = S.substr(index+1);
                break;
            }
        }
    }
    cout<<T<<endl;

}

long search(string s, char c){
    for(long i=0;i<(long)s.size();i++){
        if(s[i]==c){
            return i;
        }
    }
    return -1;
}