#include <iostream>
#include <regex>
using namespace std;
int main(void){
    string S;
    cin>>S;
    regex pattern("^(x|xx)?(oxx)*(o|ox)?$");
    if(regex_match(S, pattern)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}