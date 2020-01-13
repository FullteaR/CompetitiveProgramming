#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double triangle(int p1x,int p1y,int p2x,int p2y, int p3x, int p3y);

int main(void){
  double area=0;
  int n;
  scanf("%d",&n);
  int x1,y1,x2,y2,x3,y3;
  scanf("%d %d",&x1,&y1);
  scanf("%d %d",&x2,&y2);
  for(int i=2;i<n;i++){
    scanf("%d %d",&x3,&y3);
    area+=triangle(x1,y1,x2,y2,x3,y3);
    x2=x3;
    y2=y3;
  }
  printf("%.1f\n",area);
  return 0;
}


double triangle(int p1x,int p1y,int p2x,int p2y, int p3x, int p3y){
  p2x-=p1x;
  p3x-=p1x;
  p2y-=p1y;
  p3y-=p1y;
  return ((double)(p2x*p3y-p3x*p2y))/2;
}
