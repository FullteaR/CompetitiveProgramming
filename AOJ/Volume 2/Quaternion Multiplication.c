#include <stdio.h>

int main(void){
  while(1){
    int n;
    scanf("%d",&n);
    if(n==0)break;
    int x1,y1,z1,w1,x2,y2,z2,w2;
    for(int i=0;i<n;i++){
      scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&z1,&w1,&x2,&y2,&z2,&w2);
      printf("%d %d %d %d\n",x1*x2-y1*y2-z1*z2-w1*w2, x1*y2+x2*y1+z1*w2-w1*z2, x1*z2-y1*w2+z1*x2+w1*y2, x1*w2+y1*z2-z1*y2+w1*x2);
    }
  }
  return 0;
}
