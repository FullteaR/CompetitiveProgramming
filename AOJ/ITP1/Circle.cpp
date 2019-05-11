#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(void){
        double r;
        cin>>r;
        double area, len;
        area=M_PI*r*r;
        len=2*M_PI*r;
        printf("%f %f",area,len);
        return 0;
}
