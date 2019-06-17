#include <iostream>
using namespace std;

int main(void){
    int count[101]={0};
    int a;
    while(cin>>a){
        count[a]+=1;
    }
    int max=0;
    for(int i=1;i<=100;i++){
        if (count[i]>max){
            max=count[i];
        }
    }
    for(int i=1;i<=100;i++){
        if(count[i]==max){
            cout<<i<<endl;
        }
    }
    return 0;
}
