#include <stdio.h>

int main(void){
  int T,H,S;
  int second;
  while(1){
    scanf("%d %d %d",&T,&H,&S);
    if(T==-1 && H==-1 && S==-1)break;
    second=T*3600+H*60+S;
    second=2*3600-second;
    printf("%02d:%02d:%02d\n",second/3600,(second%3600)/60,second%60);
    second=3*second;
    printf("%02d:%02d:%02d\n",second/3600,(second%3600)/60,second%60);
  }
  return 0;
}
