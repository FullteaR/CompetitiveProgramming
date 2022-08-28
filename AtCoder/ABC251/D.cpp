#include <iostream>

using namespace std;

int main(void){
    cout<<297<<endl;
    for(int i=1;i<100;i++){
        cout<<i<<" ";
    }
    for(int i=1;i<100;i++){
        cout<<i*100<<" ";
    }
    for(int i=1;i<100;i++){
        cout<<i*10000;
        if(i<99){
            cout<<" ";
        }
        else{
            cout<<endl;
        }
    }
}