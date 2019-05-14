#include <iostream>
#include <stdio.h>
using namespace std;

int main(void){
        double a,b,c,d,e,f;
        double x,y;
        while(cin>>a>>b>>c>>d>>e>>f) {
                x=(e*c-b*f)/(a*e-b*d);
                y=(-d*c+a*f)/(a*e-b*d);
                if(x<=1e-10 and -1*x<=1e-10)x=0;
                if(y<=1e-10 and -1*y<=1e-10)y=0;
                printf("%.3f %.3f\n",x,y);
        }
        return 0;
}
