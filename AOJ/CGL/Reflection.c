#include <stdio.h>
#include <math.h>

int main(void){
  double xp1,xp2,yp1,yp2,xp,yp;
  int q;
  scanf("%lf %lf %lf %lf",&xp1,&yp1,&xp2,&yp2);
  scanf("%d",&q);
  double v1x,v1y;
  double x,y;
  v1x=(xp2-xp1)/sqrt((yp2-yp1)*(yp2-yp1)+(xp2-xp1)*(xp2-xp1));
  v1y=(yp2-yp1)/sqrt((yp2-yp1)*(yp2-yp1)+(xp2-xp1)*(xp2-xp1));
  double dot;
  for(int i=0;i<q;i++){
    scanf("%lf %lf",&xp,&yp);
    dot=(xp-xp1)*v1x+(yp-yp1)*v1y;
    x=xp1+dot*v1x;
    y=yp1+dot*v1y;
    printf("%.16f %.16f\n", 2*x-xp,2*y-yp);
  }
  return 0;
}
