#include <iostream>
using namespace std;
#define INF 100000000010
#define A 0
#define B 1
#define C 2

int main(void){
  long N;
  cin>>N;
  long* cost[3];
  for(int i=0;i<3;i++){
    cost[i]=new long[N];
    for(int j=0;j<N;j++){
      cost[i][j]=0;
    }
  }
  for(int i=0;i<N;i++){
    long a,b,c;
    cin>>a>>b>>c;
    if(i==0){
      cost[A][i]=a;
      cost[B][i]=b;
      cost[C][i]=c;
    }
    else{
      cost[A][i]=max(cost[B][i-1],cost[C][i-1])+a;
      cost[B][i]=max(cost[A][i-1],cost[C][i-1])+b;
      cost[C][i]=max(cost[A][i-1],cost[B][i-1])+c;
    }
  }
  long retval=0;
  for(int i=0;i<3;i++){
    retval=max(cost[i][N-1],retval);
  }
  cout<<retval<<endl;

  return 0;
}
