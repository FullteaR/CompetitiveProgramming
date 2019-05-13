#include <iostream>
#include <stdio.h>
using namespace std;
#include <stdlib.h>
int main(void){
        int n,m;
        cin>>n>>m;
        int* a=(int*)malloc(sizeof(int)*n*m);
        int* b=(int*)malloc(sizeof(int)*m);
        int* retval=(int*)malloc(sizeof(int)*n);

        for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                        cin>>a[i*m+j];
                }
                retval[i]=0;//initialize
        }
        for(int j=0; j<m; j++) {
                b[j]=0;
                cin>>b[j];
        }

        for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                        retval[i]+=b[j]*a[i*m+j];
                }
                printf("%d\n",retval[i]);
        }


        return 0;
}
