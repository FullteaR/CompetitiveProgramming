#include <iostream>
using namespace std;

int main(void){
    string S;
    cin>>S;
    if(S[S.size()-1]=='r'){
        cout<<"er"<<endl;
    }
    else{
        cout<<"ist"<<endl;
    }
    return 0;
}