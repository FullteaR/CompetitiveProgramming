#include <stdio.h>


int main(void){
  int q;
  scanf("%d",&q);

  double x1,y1,x2,y2,x3,y3,x4,y4;
  double x,y;//直線の交点
  double det;//行列式
  for(int i=0;i<q;i++){
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    det=(x2-x1)*(y4-y3)-(y2-y1)*(x4-x3);
    x=((x3-x4)*(x1*y2-x2*y1)+(x2-x1)*(x3*y4-x4*y3))/det;
    y=((y3-y4)*(x1*y2-x2*y1)+(y2-y1)*(x3*y4-x4*y3))/det;
    printf("%.16lf %.16lf\n",x,y);
  }
  return 0;
}
