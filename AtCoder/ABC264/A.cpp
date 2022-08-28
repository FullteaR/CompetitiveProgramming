#include <iostream>
using namespace std;

int main(void){
    string S = "atcoder";
    int L,R;
    cin>>L>>R;
    for(int i=L;i<=R;i++){
        cout<<S[i-1];
    }
    cout<<endl;
    return 0;
}