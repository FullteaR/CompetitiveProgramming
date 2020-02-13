#include <stdio.h>

int main(void){
  int ball[3]={1,0,0};
  char c1,c2;
  int ind1,ind2;
  int tmp;
  while(scanf("%c,%c\n",&c1,&c2)!=EOF){
    ind1=(int)(c1-'A');
    ind2=(int)(c2-'A');
    tmp=ball[ind1];
    ball[ind1]=ball[ind2];
    ball[ind2]=tmp;
  }


  for(int i=0;i<3;i++){
    if(ball[i]==1){
      printf("%c\n",i+'A');
    }
  }
  return 0;
}
