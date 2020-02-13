#include <stdio.h>
#include <math.h>
int main(void){
  int cost,num;
  int totalCost=0;
  int i=0;
  double ave=0.0;
  while(scanf("%d,%d",&cost,&num)!=EOF){
    totalCost+=(cost*num);
    ave+=num;
    i++;
  }
  printf("%d\n%d\n",totalCost,(int)round(ave/i));
  return 0;
}
