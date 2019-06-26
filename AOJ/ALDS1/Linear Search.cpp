#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
    int n,q;
    cin>>n;
    int* S=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        cin>>S[i];
    }
    cin>>q;
    int* T=(int*)malloc(q*sizeof(int));
    for(int i=0;i<q;i++){
        cin>>T[i];
    }
    bool exist;
    int C=0;
    for(int i=0;i<q;i++){
        exist=false;
        for(int j=0;j<n;j++){
            if(S[j]==T[i]){
                exist=true;
            }
        }
        if(exist){
            C++;
        }
    }
    cout<<C<<endl;
    return 0;
}
