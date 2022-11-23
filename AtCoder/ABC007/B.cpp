#include <iostream>
using namespace std;

int main(void) {
    string S;
    cin>>S;
    if(S.size()==1 and S[0]=='a'){
        cout<<-1<<endl;
        return 0;
    }
    cout<<'a'<<endl;
    return 0;
}