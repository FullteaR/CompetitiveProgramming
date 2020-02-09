#include <stdio.h>

int max(int a,int b);

int main(void){
  int paper[14][14];
  for(int i=0;i<14;i++){
    for(int j=0;j<14;j++){
      paper[i][j]=0;
    }
  }
  int x,y,s;
  while(scanf("%d,%d,%d",&x,&y,&s)!=EOF){
    x+=2;
    y+=2;
    switch(s){
      case 3:
        paper[x-2][y]+=1;
        paper[x][y-2]+=1;
        paper[x+2][y]+=1;
        paper[x][y+2]+=1;
      case 2:
        paper[x-1][y-1]+=1;
        paper[x-1][y+1]+=1;
        paper[x+1][y-1]+=1;
        paper[x+1][y+1]+=1;
      case 1:
        paper[x-1][y]+=1;
        paper[x][y-1]+=1;
        paper[x+1][y]+=1;
        paper[x][y+1]+=1;
        paper[x][y]+=1;
    }
  }
  int white=0;
  int ink=0;
  for(int i=2;i<12;i++){
    for(int j=2;j<12;j++){
      if(paper[i][j]==0){
        white+=1;
      }
      else{
        ink=max(ink,paper[i][j]);
      }
    }
  }
  printf("%d\n%d\n",white,ink);
  return 0;
}

int max(int a, int b){
  if(a<b){
    return b;
  }
  else{
    return a;
  }
}
