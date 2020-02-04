#include <stdio.h>

int main(void){
  char pattern[8][8];
  char c1,c2,c3,c4,c5,c6,c7,c8,_;
  for(int i=0;i<8;i++){
    scanf("%c%c%c%c%c%c%c%c%c",&c1,&c2,&c3,&c4,&c5,&c6,&c7,&c8,&_);
    pattern[i][0]=c1;
    pattern[i][1]=c2;
    pattern[i][2]=c3;
    pattern[i][3]=c4;
    pattern[i][4]=c5;
    pattern[i][5]=c6;
    pattern[i][6]=c7;
    pattern[i][7]=c8;
  }
  printf("90\n");
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      printf("%c",pattern[7-j][i]);
    }
    printf("\n");
  }
  printf("180\n");
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      printf("%c",pattern[7-i][7-j]);
    }
    printf("\n");
  }
  printf("270\n");
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      printf("%c",pattern[j][7-i]);
    }
    printf("\n");
  }
  return 0;
}
