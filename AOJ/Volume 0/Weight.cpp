#include <iostream>
#include <math.h>
using namespace std;

int main(void){
    int n;
    int weight[10];
    bool flag;
    while(cin>>n){
        for(int i=0;i<10;i++){
            weight[i]=0;
        }
        flag=false;
        for(int i=9;i>=0;i--){
            if(pow(2,i)<=n){
                weight[i]=1;
                n-=pow(2,i);
            }
        }
        for(int i=0;i<10;i++){
            if(flag==false and weight[i]==1){
                flag=true;
                cout<<pow(2,i);
            }
            else if(weight[i]==1){
                cout<<" "<<pow(2,i);
            }
        }
        cout<<endl;
    }
}
