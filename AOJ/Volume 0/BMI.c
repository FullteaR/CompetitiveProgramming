#include <stdio.h>

int main(void){
  int s;
  double w;
  double h;
  double bmi;
  while(scanf("%d,%lf,%lf",&s,&w,&h)!=EOF){
    bmi=w/(h*h);
    if(bmi>=25){
      printf("%d\n",s);
    }
  }
  return 0;
}
