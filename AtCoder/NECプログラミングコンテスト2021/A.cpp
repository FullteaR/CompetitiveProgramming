#include <iostream>
using namespace std;

int main(void){
    string S1;
    string S2;
    cin>>S1;
    cin>>S2;
    bool retval=true;
    if(S1=="#." and S2==".#"){
        retval=false;
    }
    else if(S1==".#" and S2=="#."){
        retval=false;
    }
    if(retval){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}