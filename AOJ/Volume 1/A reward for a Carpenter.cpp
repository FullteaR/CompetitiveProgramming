#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define INF 100000010

using namespace std;

int main(void){
  int n,m;
  int a,b,c,d;
  int s,g,V,P;
  cin>>n;
  cin>>m;
  map<int,int> mp[n];
  for(int i=0;i<m;i++){
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    a--;
    b--;
    mp[a][b]=c;
    mp[b][a]=d;
  }
  scanf("%d,%d,%d,%d",&s,&g,&V,&P);
  s--;
  g--;
  int iki[n];
  int kaeri[n];
  for(int i=0;i<n;i++){
    iki[i]=INF;
    kaeri[i]=INF;
  }
  iki[s]=0;
  kaeri[g]=0;

  vector<int> next;
  vector<int> _next;
  next.push_back(s);
  for(int i=0;i<20;i++){
    _next.clear();
    for(int j=0;j<next.size();j++){
      int city=next[j];
      for(auto iter=mp[city].begin();iter!=mp[city].end();iter++){
        int city_next_to = iter->first;
        int cost = iter->second;
        if(iki[city_next_to]>iki[city]+cost){
          iki[city_next_to]=iki[city]+cost;
          _next.push_back(city_next_to);
        }
      }
    }
    next.clear();
    copy(_next.begin(),_next.end(),back_inserter(next));
  }

  next.clear();
  next.push_back(g);
  for(int i=0;i<20;i++){
    _next.clear();
    for(int j=0;j<next.size();j++){
      int city=next[j];
      for(auto iter=mp[city].begin();iter!=mp[city].end();iter++){
        int city_next_to = iter->first;
        int cost = iter->second;
        if(kaeri[city_next_to]>kaeri[city]+cost){
          kaeri[city_next_to]=kaeri[city]+cost;
          _next.push_back(city_next_to);
        }
      }
    }
    next.clear();
    copy(_next.begin(),_next.end(),back_inserter(next));
  }
  cout<<V-P-iki[g]-kaeri[s]<<endl;
  return 0;
}
