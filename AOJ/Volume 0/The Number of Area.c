#include <stdio.h>

int main(void){
  int n;
  while(scanf("%d",&n)!=EOF){
    if(n==1){
      printf("2\n");
      continue;
    }

    int a=4;
    for(int i=3;i<=n;i++){
      a+=i;
    }
    printf("%d\n",a);
  }
  return 0;
}
