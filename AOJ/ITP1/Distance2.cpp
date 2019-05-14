#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

double Dxy(int* x,int* y,int n, int p);

int main(void){
        int n=0;
        int x[100]={0};
        int y[100]={0};
        cin>>n;
        for(int i=0; i<n; i++) {
                cin>>x[i];
        }
        for(int i=0; i<n; i++) {
                cin>>y[i];
        }
        for(int i=1; i<=3; i++) {
                printf("%lf\n",Dxy(x,y,n,i));
        }

        int p_inf=0;
        for(int i=0; i<n; i++) {
                p_inf=max(abs(x[i]-y[i]),p_inf);
        }
        cout<<p_inf<<endl;

        return 0;
}


double Dxy(int* x,int* y,int n, int p){
        double d=0;
        for(int i=0; i<n; i++) {
                d+=pow(abs(x[i]-y[i]),p);
        }
        d=pow(d,1.0/p);
        return d;
}
