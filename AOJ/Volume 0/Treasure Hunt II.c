#include <stdio.h>
#include <math.h>

int main(void){
  double x,y;
  int n;
  double vx,vy;
  double r;
  while(1){
    scanf("%d",&n);
    if(n==-1)break;
    x=1;
    y=0;
    for(int i=0;i<n-1;i++){
      vx=-y;
      vy=x;
      r=sqrt(x*x+y*y);
      vx=vx/r;
      vy=vy/r;
      x+=vx;
      y+=vy;
    }
    printf("%lf\n%lf\n",x,y);
  }
  return 0;
}
