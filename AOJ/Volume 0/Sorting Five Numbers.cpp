#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int a[5];
    int tmp;
    for(int i=0;i<5;i++){
        cin>>tmp;
        a[i]=tmp*(-1);
    }
    sort(a,a+5);
    for(int i=0;i<5;i++){
        cout<<-1*a[i];
        if(i<4){
            cout<<" ";
        }
        else{
            cout<<endl;
        }
    }
    return 0;
}
