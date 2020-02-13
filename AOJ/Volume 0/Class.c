#include <stdio.h>

int main(void){
  double d;
  while(scanf("%lf",&d)!=EOF){
    if(d<=48)printf("light fly\n");
    else if(d<=51)printf("fly\n");
    else if(d<=54)printf("bantam\n");
    else if(d<=57)printf("feather\n");
    else if(d<=60)printf("light\n");
    else if(d<=64)printf("light welter\n");
    else if(d<=69)printf("welter\n");
    else if(d<=75)printf("light middle\n");
    else if(d<=81)printf("middle\n");
    else if(d<=91)printf("light heavy\n");
    else printf("heavy\n");
  }
  return 0;
}
