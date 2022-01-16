#include <iostream>
using namespace std;

int main(void){
    int H,R;
    cin>>H>>R;
    if(H+R==0){
        cout<<0<<endl;
    }
    else if(H+R>0){
        cout<<1<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}