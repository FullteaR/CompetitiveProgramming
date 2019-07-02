#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
    int n,q;
    cin>>n;
    int* A=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cin>>q;
    int* m=(int*)malloc(sizeof(int)*q);
    for(int i=0;i<q;i++){
        cin>>m[i];
    }
    int table[20*2000+5]={0};
    table[0]=1;
    for(int i=0;i<n;i++){
        for(int j=20*2000;j>=0;j--){
            if(table[j]==1){
                table[j+A[i]]=1;
            }
        }
    }
    for(int i=0;i<q;i++){
        if(table[m[i]]==1){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
