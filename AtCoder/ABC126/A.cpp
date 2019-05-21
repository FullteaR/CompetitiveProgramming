#include <iostream>
using namespace std;

int main(void){
        int N,K;
        char S[55];
        cin>>N>>K;
        cin>>S;
        S[K-1]=S[K-1]-'A'+'a';
        cout<<S<<endl;
        return 0;
}
