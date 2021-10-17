#include <iostream>
using namespace std;

int main(void){
    int X;
    cin>>X;
    if(X%100==0 and X>0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}