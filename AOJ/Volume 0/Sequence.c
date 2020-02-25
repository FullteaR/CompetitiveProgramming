#include <stdio.h>

int main(void){
  double a;
  double s;
  while(scanf("%lf",&a)!=EOF){
    s=a;
    for(int i=2;i<=10;i++){
      if(i%2==0)a=a*2;
      else a=a/3;
      s+=a;
    }
    printf("%.16lf\n",s);
  }
  return 0;
}
