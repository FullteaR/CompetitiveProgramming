#include <iostream>
using namespace std;

int Max(int a,int b,int c);

int main(void){
  int N,W;
  cin>>N>>W;
  int tables[N+1][W+1];
  for(int i=0;i<N+1;i++){
    for(int j=0;j<W+1;j++){
      tables[i][j]=0;
    }
  }
  int v[N+1];
  int w[N+1];
  v[0]=0;
  w[0]=0;
  for(int i=1;i<N+1;i++){
    cin>>v[i]>>w[i];
  }

  for(int i=1;i<N+1;i++){
    for(int j=0;j<W+1;j++){
      if(j>=w[i]){
        tables[i][j]=Max(tables[i-1][j],tables[i-1][j-w[i]]+v[i],tables[i][j-w[i]]+v[i]);
      }
      else{
        tables[i][j]=tables[i-1][j];
      }

    }
  }

  cout<<tables[N][W]<<endl;
  return 0;
}

int Max(int a,int b,int c){
  int retval=0;
  int values[3]={a,b,c};
  for(int i=0;i<3;i++){
    retval=max(retval,values[i]);
  }
  return retval;
}
