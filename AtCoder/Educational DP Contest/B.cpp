#include <iostream>
using namespace std;
#define INF 100000000010

int main(void){
  long N,K;
  cin>>N>>K;
  long* h = new long[N];
  long* cost = new long[N];
  for(int i=0;i<N;i++){
    cin>>h[i];
    cost[i]=INF;
  }
  cost[0]=0;
  for(int i=1;i<N;i++){
    for(int k=1;k<=K;k++){
      if(i-k>=0){
        cost[i]=min(cost[i], abs(h[i]-h[i-k])+cost[i-k]);
      }
    }
  }
  cout<<cost[N-1]<<endl;
  return 0;
}
