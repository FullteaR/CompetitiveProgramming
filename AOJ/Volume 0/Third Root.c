#include <stdio.h>
#include <math.h>

double tr(int q);

int main(void){
  int q;
  while(1){
    scanf("%d",&q);
    if(q==-1)break;
    printf("%lf\n",tr(q));
  }
  return 0;
}

double tr(int q){
  double x=q*1.0/2;
  while(fabs(x*x*x-q)>=0.00001*q){
    x=x-(x*x*x-q)/(3.0*x*x);
  }
  return x;
}
