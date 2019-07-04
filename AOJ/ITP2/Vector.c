#include <stdlib.h>
#include <stdio.h>

int main(void){
  int q;
  scanf("%d",&q);
  int A[200010];
  int pointer=0;
  int command;
  int x;
  int p;
  for(int i=0;i<q;i++){
    scanf("%d",&command);
    if(command==0){
      scanf("%d",&x);
      A[pointer]=x;
      pointer++;
    }
    if(command==1){
      scanf("%d",&p);
      printf("%d\n",A[p]);
    }
    if(command==2){
      pointer-=1;
    }
  }
  return 0;
}
