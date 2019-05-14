#include<iostream>
#include <string>
using namespace std;

int main(void){
    string str;
    int n;
    string command;
    int arg1,arg2;
    string replace;
    cin>>str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>command>>arg1>>arg2;
        if(command=="replace"){
                cin>>replace;
                str=str.substr(0,arg1)+replace+str.substr(arg2+1,-1);
            }
        else if(command=="reverse"){
replace=str.substr(arg1,arg2+1);
                reverse(replace.begin(),replace.end());
                str=str.substr(0,arg1)+replace+str.substr(arg2+1,-1);
            }
        else if(command=="print"){
                cout<<str.substr(arg1,arg2+1)<<endl;
        }
    }
    return 0;
}
