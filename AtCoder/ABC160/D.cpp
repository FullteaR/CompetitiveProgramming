#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define INF 100000010;

int main(void){
  int N,X,Y;
  cin>>N>>X>>Y;
  X--;
  Y--;
  map<int,int> d;
  for(int i=0;i<N;i++){
    d[i]=0;
  }
  vector<int> G[N];
  for(int i=0;i<N;i++){
    G[i].clear();
  }
  G[0].push_back(1);
  for(int i=1;i<N-1;i++){
    G[i].push_back(i-1);
    G[i].push_back(i+1);
  }
  G[N-1].push_back(N-2);
  G[X].push_back(Y);
  G[Y].push_back(X);
  for(int start=0;start<N;start++){
    int dist[N];
    for(int i=0;i<N;i++){
      dist[i]=INF;
    }
    dist[start]=0;
    vector<int> next;
    vector<int> _next;
    next.push_back(start);
    while(next.empty()==false){
      _next.clear();
      for(auto iter=next.begin();iter!=next.end();iter++){
        auto neighbor=G[*iter];
        for(auto iter2=neighbor.begin();iter2!=neighbor.end();iter2++){
          if(dist[*iter2]>dist[*iter]+1){
            dist[*iter2]=dist[*iter]+1;
            _next.push_back(*iter2);
          }
        }
      }
      next=_next;
    }
    for(int i=0;i<N;i++){
      d[dist[i]]++;
    }
  }
  for(int i=1;i<N;i++){
    cout<<d[i]/2<<endl;
  }
  return 0;
}
