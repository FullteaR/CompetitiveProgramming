#include <stdio.h>

int main(void){
  double high=0;
  double low=10000001000;
  double h;
  while(scanf("%lf",&h)!=EOF){
    if(high<h)high=h;
    if(low>h)low=h;
  }
  printf("%lf",high-low);
  return 0;
}
