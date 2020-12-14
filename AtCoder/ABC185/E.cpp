#include <iostream>
using namespace std;

int main(void){
  int N,M;
  cin>>N>>M;
  long* A = new long[N];
  long* B = new long[M];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int i=0;i<M;i++){
    cin>>B[i];
  }

  long** table = new long*[N+1];
  for(int i=0;i<=N;i++){
    table[i]=new long[M+1];
  }
  for(int i=0;i<=N;i++){
    for(int j=0;j<=M;j++){
      table[i][j]=0;
    }
  }
  for(int i=0;i<=N;i++){
    table[i][0]=i;
  }
  for(int i=0;i<=M;i++){
    table[0][i]=i;
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      table[i][j]=min(table[i-1][j]+1,table[i][j-1]+1);
      if(A[i-1]==B[j-1]){
        table[i][j]=min(table[i][j],table[i-1][j-1]);
      }
      else{
        table[i][j]=min(table[i][j],table[i-1][j-1]+1);
      }
    }
  }
  cout<<table[N][M]<<endl;
  return 0;
}
