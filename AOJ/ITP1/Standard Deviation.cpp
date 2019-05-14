#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main(void){
        int n;
        int tmp=0;
        double Ex2;
        double Ex;
        double V;
        while(1) {
                Ex=0;
                Ex2=0;
                tmp=0;
                cin>>n;
                if(n==0) {return 0;}
                for(int i=0; i<n; i++) {
                        cin>>tmp;
                        Ex+=tmp;
                        Ex2+=tmp*tmp;
                }
                V=Ex2/n-(Ex/n)*(Ex/n);
                if(V<=0.001) {
                        printf("0\n");
                }
                else{
                        printf("%lf\n",sqrt(V));
                }

        }
}
