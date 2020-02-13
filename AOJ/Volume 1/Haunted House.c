#include <stdio.h>

int main(void){
  char name[30];
  int a;
  int b;
  while(scanf("%s %d %d",name,&a,&b)!=EOF){
    printf("%s %d %d\n",name,a+b,200*a+300*b);
  }
  return 0;
}
