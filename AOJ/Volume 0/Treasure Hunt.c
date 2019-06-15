#include <math.h>
#include <stdio.h>
using namespace std;

int main(void){
    double x=0;
    double y=0;
    double angle=90;
    int d,a;
    while(1){
        scanf("%d,%d",&d,&a);
        if(d==0 and a==0){
            printf("%d\n%d\n",(int)x,(int)y);
            return 0;
        }
        x+=d*cos(angle*2*M_PI/360);
        y+=d*sin(angle*2*M_PI/360);
        angle-=a;
    }

}
