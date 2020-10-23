#include <iostream>
using namespace std;
#define INF 10000000010

int main(void){
  long N;
  cin>>N;
  long* h = new long[N];
  long* cost = new long[N];
  for(int i=0;i<N;i++){
    cin>>h[i];
    cost[i]=INF;
  }
  cost[0]=0;
  cost[1]=abs(h[1]-h[0]);
  for(int i=2;i<N;i++){
    cost[i]=min(abs(h[i]-h[i-1])+cost[i-1],abs(h[i]-h[i-2])+cost[i-2]);
  }
  cout<<cost[N-1]<<endl;
  return 0;
}
