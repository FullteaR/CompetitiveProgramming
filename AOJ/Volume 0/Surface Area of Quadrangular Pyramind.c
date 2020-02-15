#include <stdio.h>
#include <math.h>

int main(void){
  double x,h,S;
  while(1){
    scanf("%lf",&x);
    scanf("%lf",&h);

    if(x==0 && h==0)break;
    S=0;
    S+=x*x;
    S+=2*x*sqrt(h*h+(x*x/4));
    printf("%lf\n",S);
  }
  return 0;
}
