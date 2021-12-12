#include <iostream>
using namespace std;

int main(void){
    int S,T,X;
    cin>>S>>T>>X;
    if(S<T){
        if(S<=X and X<T){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    else{
        if(T<=X and X<S){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}