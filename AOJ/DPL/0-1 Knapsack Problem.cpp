#include <iostream>
using namespace std;

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
        tables[i][j]=max(tables[i-1][j],tables[i-1][j-w[i]]+v[i]);
      }
      else{
        tables[i][j]=tables[i-1][j];
      }

    }
  }

  cout<<tables[N][W]<<endl;
  return 0;
}
