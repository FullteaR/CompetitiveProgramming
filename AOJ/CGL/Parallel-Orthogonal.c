#include <stdio.h>

int main(void){
  double xp0,yp0,xp1,yp1,xp2,yp2,xp3,yp3;
  int q;
  scanf("%d",&q);
  for(int i=0;i<q;i++){
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&xp0,&yp0,&xp1,&yp1,&xp2,&yp2,&xp3,&yp3);
    if((yp1-yp0)*(xp3-xp2)==(yp3-yp2)*(xp1-xp0)){
      printf("2\n");
    }
    else if((yp1-yp0)*(yp3-yp2)+(xp1-xp0)*(xp3-xp2)==0){
      printf("1\n");
    }
    else{
      printf("0\n");
    }
  }
  return 0;
}
