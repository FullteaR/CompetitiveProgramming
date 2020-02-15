#include <stdio.h>


int main(void){
  int n;
  int a,v;
  int retNum=100;
  int retFish=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d %d",&a,&v);
    if(v>retFish){
      retFish=v;
      retNum=a;
    }
    else if(v==retFish){
      if(retNum>a){
        retNum=a;
      }
    }
  }
  printf("%d %d\n",retNum,retFish);
  return 0;
}
