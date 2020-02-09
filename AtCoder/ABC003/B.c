#include <stdio.h>

int main(void){
  char S[15];
  char T[15];
  scanf("%s",S);
  scanf("%s",T);

  int i=0;
  int win=1;
  while(S[i]!='\0'){
    if(S[i]==T[i]);
    else if(S[i]=='@'){
      if(T[i]=='a' || T[i]=='t' || T[i]=='c' || T[i]=='o' || T[i]=='d' || T[i]=='e' || T[i]=='r');
      else win=0;
    }
    else if(T[i]=='@'){
      if(S[i]=='a' || S[i]=='t' || S[i]=='c' || S[i]=='o' || S[i]=='d' || S[i]=='e' || S[i]=='r');
      else win=0;
    }
    else win=0;
    i++;
  }
  if(win==1){
    printf("You can win\n");
  }
  else{
    printf("You will lose\n");
  }

  return 0;
}
