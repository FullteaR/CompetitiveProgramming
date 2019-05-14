#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(void){
        int w,n,a,b;
        int tmp;
        cin>>w;
        int amida[30];
        for(int i=0; i<30; i++) {
                amida[i]=i+1;
        }
        cin>>n;
        for(int i=0; i<n; i++) {
                scanf("%d,%d",&a,&b,stdin);
                tmp=amida[a-1];
                amida[a-1]=amida[b-1];
                amida[b-1]=tmp;
        }
        for(int i=0; i<w; i++) {
                cout<<amida[i]<<endl;
        }

}
