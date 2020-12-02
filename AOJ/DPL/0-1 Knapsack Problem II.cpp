#include <iostream>
using namespace std;
#define INF 1000000010

int main(void){
  int N,W;
  cin>>N>>W;
  long* v = new long[N];
  long* w = new long[N];
  for(int i=0;i<N;i++){
    cin>>v[i]>>w[i];
  }
  long** table = new long* [N+1];
  for(int i=0;i<N+1;i++){
    table[i]=new long[10010];
  }
  //table[i][v]=i個目までの商品で、価値vを達成できる重さの最小値
  for(int i=0;i<N+1;i++){
    table[i][0]=0;
  }
  for(int i=1;i<10010;i++){
    table[0][i]=INF;
  }
  for(int i=1;i<N+1;i++){
    for(int j=1;j<10010;j++){
      table[i][j] = min(table[i-1][j-v[i-1]]+w[i-1], table[i-1][j]);
    }
  }
  long retval=0;
  for(long i=0;i<10010;i++){
    if(table[N][i]<=W){
      retval=max(i,retval);
    }
  }
  cout<<retval<<endl;
  return 0;
}
