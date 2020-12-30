#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define INF 1000000010

int main(void){
  int W;
  cin>>W;
  int N,K;
  cin>>N>>K;
  //table[n][w][k]=1~nのスクリーンショットからk枚を用いて、幅w以内に抑えたときの重要度の最大値
  long*** table=new long**[N+1];
  for(int n=0;n<=N;n++){
    table[n]=new long*[W+1];
    for(int w=0;w<=W;w++){
      table[n][w]=new long[K+1];
      for(int k=0;k<=K;k++){
        table[n][w][k]=0;
      }
    }
  }



  vector<pair<int, int> > v;
  v.clear();
  for(int i=0;i<N;i++){
    int A,B;
    cin>>A>>B;
    v.push_back(make_pair(A,B));
  }

  for(int n=1;n<=N;n++){
    int A=v[n-1].first;
    int B=v[n-1].second;
    for(int w=0;w<=W;w++){
      for(int k=1;k<=K;k++){
        if(w>=A){
          table[n][w][k]=max(table[n-1][w][k],table[n-1][w-A][k-1]+B);
        }
        else{
          table[n][w][k]=table[n-1][w][k];
        }
      }
    }
  }
  long retval=0;
  for(int k=0;k<=K;k++){
    for(int w=0;w<=W;w++){
      retval=max(retval, table[N][w][k]);
    }
  }
  cout<<retval<<endl;
  return 0;
}
