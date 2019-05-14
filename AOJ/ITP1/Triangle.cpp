#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main(void){
        int a,b,C;
        cin>>a>>b>>C;
        double S,L,h;
        S=a*b*sin(C*M_PI/180)/2;
        L=a+b+sqrt(a*a+b*b-2*a*b*cos(C*M_PI/180));
        h=2*S/a;
        printf("%lf\n%lf\n%lf\n",S,L,h);
        return 0;
}
