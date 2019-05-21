#include <iostream>
#include <stdio.h>
using namespace std;


int main(void){
        int n=0;
        while(1) {
                cin>>n;
                if(n==0) return 0;
                int a[n+1][n+1];
                int s;
                for(int i=0; i<n; i++) {
                        s=0;
                        for(int j=0; j<n; j++) {
                                a[i][j]=0;
                                cin>>a[i][j];
                                s+=a[i][j];
                        }
                        a[i][n]=s;
                }

                for(int j=0; j<n+1; j++) {
                        s=0;
                        for(int i=0; i<n; i++) {
                                s+=a[i][j];
                        }
                        a[n][j]=s;
                }

                for(int i=0; i<n+1; i++) {
                        for(int j=0; j<n+1; j++) {
                                printf("%5d",a[i][j]);
                        }
                        printf("\n");

                }
        }

        return 0;

}
