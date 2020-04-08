#include <iostream>
#include <algorithm>
using namespace std;

long calc(int X, int Y, int** ski);

int main(void){
  int X,Y;
  while(true){
    cin>>X>>Y;
    if(X==0 and Y==0){break;}
    int** ski=(int**)malloc(sizeof(int*)*Y);
    for(int i=0;i<Y;i++){
      ski[i]=(int*)malloc(sizeof(int)*X);
      for(int j=0;j<X;j++){
        cin>>ski[i][j];
      }
    }
    cout<<calc(X,Y,ski)<<endl;
    for(int i=0;i<Y;i++){
      free(ski[i]);
    }
    free(ski);
  }
  return 0;
}

long calc(int X, int Y, int** ski){
  long** pattern=(long**)malloc(sizeof(long*)*Y);
  for(int i=0;i<Y;i++){
    pattern[i]=(long*)malloc(sizeof(long)*X);
    for(int j=0;j<X;j++){
      pattern[i][j]=0;
    }
  }

  for(int j=0;j<X;j++){
    if(ski[0][j]==0){
      pattern[0][j]=1;
    }
    else{
      pattern[0][j]=0;
    }
  }
  for(int i=1;i<Y;i++){
    for(int j=0;j<X;j++){
      if(ski[i][j]==1){
        pattern[i][j]=0;
      }
      else if(ski[i][j]==2){
        pattern[i][j]=0;
        if(ski[i-1][j]==0){
          pattern[i][j]+=pattern[i-1][j];
        }
        if(i>=2 and ski[i-2][j]==2){
          pattern[i][j]+=pattern[i-2][j];
        }
      }
      else{//ski[i][j]=0
        pattern[i][j]=0;
        if(j>0 and ski[i-1][j-1]==0){
          pattern[i][j]+=pattern[i-1][j-1];
        }
        if(ski[i-1][j]==0){
          pattern[i][j]+=pattern[i-1][j];
        }
        if(j<X-1 and ski[i-1][j+1]==0){
          pattern[i][j]+=pattern[i-1][j+1];
        }
        if(i>=2 and ski[i-2][j]==2){
          pattern[i][j]+=pattern[i-2][j];
        }
      }
    }
  }

  long retval=0;
  for(int j=0;j<X;j++){
    retval+=pattern[Y-1][j];
    if(Y>=2 and ski[Y-2][j]==2){
      retval+=pattern[Y-2][j];
    }
  }
  return retval;
}
