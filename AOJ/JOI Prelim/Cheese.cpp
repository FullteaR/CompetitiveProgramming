#include <iostream>
#include <utility>
#include <set>
#define INF 1000000010
using namespace std;

long distance(bool** mp, long H, long W, pair<long, long>* S, pair<long, long>* G);

int main(void){
  long H,W,N;
  cin>>H>>W>>N;
  pair<long, long>* cheeses = new pair<long,long> [N+1];
  char** area = new char*[H];
  for(long i=0;i<H;i++){
    area[i] = new char[W];
    for(long j=0;j<W;j++){
      cin>>area[i][j];
      if(area[i][j]=='X')continue;
      else if(area[i][j]=='S'){
        cheeses[0]=make_pair(i,j);
      }
      else{
        cheeses[area[i][j]-'0']=make_pair(i,j);
      }
    }
  }

  H+=2;
  W+=2;
  bool** mp = new bool*[H];
  for(long i=0;i<H;i++){
    mp[i] = new bool[W];
  }
  for(long i=1;i<H-1;i++){
    for(long j=1;j<W-1;j++){
      mp[i][j]=(area[i-1][j-1]!='X');
    }
  }
  for(long i=0;i<H;i++){
    mp[i][0]=false;
    mp[i][W-1]=false;
  }
  for(long j=0;j<W;j++){
    mp[0][j]=false;
    mp[H-1][j]=false;
  }

  long retval=0;
  for(int i=0;i<N;i++){
    retval+=distance(mp,H,W,&(cheeses[i]),&(cheeses[i+1]));
  }
  cout<<retval<<endl;
  return 0;
}

long distance(bool** mp, long H, long W, pair<long, long>* S, pair<long, long>* G){
  long** dist = new long* [H];
  for(long i=0;i<H;i++){
    dist[i] = new long[W];
    for(long j=0;j<W;j++){
      dist[i][j] = INF;
    }
  }
  set<pair<long, long> > next;
  next.clear();
  next.insert(make_pair(S->first+1, S->second+1));
  dist[S->first+1][S->second+1]=0;
  while(!next.empty()){
    set<pair<long, long> > _next;
    _next.clear();
    for(auto iter=next.begin();iter!=next.end();iter++){
      if(mp[iter->first][iter->second+1]==false){
        ;
      }
      else if(dist[iter->first][iter->second+1]>dist[iter->first][iter->second]+1){
        dist[iter->first][iter->second+1] = dist[iter->first][iter->second]+1;
        _next.insert(make_pair(iter->first,iter->second+1));
      }
      if(mp[iter->first][iter->second-1]==false){
        ;
      }
      else if(dist[iter->first][iter->second-1]>dist[iter->first][iter->second]+1){
        dist[iter->first][iter->second-1] = dist[iter->first][iter->second]+1;
        _next.insert(make_pair(iter->first,iter->second-1));
      }
      if(mp[iter->first+1][iter->second]==false){
        ;
      }
      else if(dist[iter->first+1][iter->second]>dist[iter->first][iter->second]+1){
        dist[iter->first+1][iter->second] = dist[iter->first][iter->second]+1;
        _next.insert(make_pair(iter->first+1,iter->second));
      }
      if(mp[iter->first-1][iter->second]==false){
        ;
      }
      else if(dist[iter->first-1][iter->second]>dist[iter->first][iter->second]+1){
        dist[iter->first-1][iter->second] = dist[iter->first][iter->second]+1;
        _next.insert(make_pair(iter->first-1,iter->second));
      }
    }
    next.swap(_next);
  }
  return dist[G->first+1][G->second+1];
}
