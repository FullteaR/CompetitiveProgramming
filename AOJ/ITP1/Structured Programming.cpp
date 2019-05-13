#include <iostream>
#include <stdio.h>
using namespace std;

int contain3(int i){
    int mod;
    while(i>0){
        mod=i%10;
        if(mod==3){
            return 1;
        }
        i=i/10;
    }
    return 0;
}

int main(void){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%3==0){
            printf(" %d",i);
        }
        else if(contain3(i)){
            printf(" %d",i);
        }
    }
    printf("\n");

    return 0;
}
