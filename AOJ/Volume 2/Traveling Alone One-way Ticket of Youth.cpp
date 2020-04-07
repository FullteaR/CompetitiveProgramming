#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#define INF 100000100
using namespace std;


int minimize(int start, int goal, map<int,int>* mp,int n);


int main(void){
  int n,m;
  while(true){
    cin>>n>>m;
    if(n==0 and m==0){break;}
    map<int,int> costs[n];
    map<int,int> times[n];
    int a,b,c,t;
    for(int i=0;i<n;i++){
      cin>>a>>b>>c>>t;
      a--;
      b--;
      costs[a][b]=c;
      costs[b][a]=c;
      times[a][b]=t;
      times[b][a]=t;
    }
    int k;
    cin>>k;
    int p,q,r;
    for(int i=0;i<k;i++){
      cin>>p>>q>>r;
      p--;
      q--;
      if(r==0){
        cout<<minimize(p,q,costs,n)<<endl;
      }
      else{
        cout<<minimize(p,q,times,n)<<endl;
      }
    }
  }
  return 0;
}

int minimize(int start, int goal, map<int,int>* mp,int n){
  int d[n];
  for(int i=0;i<n;i++){
    d[i]=INF;
  }
  d[start]=0;
  vector<int> next,_next;
  next.push_back(start);
  while(next.size()>0){
    _next.clear();
    for(auto iter=next.begin();iter!=next.end();iter++){
      int s=*iter;
      for(auto iter2=mp[s].begin();iter2!=mp[s].end();iter2++){
        int key=iter2->first;
        int value=iter2->second;
        if(d[key]>d[s]+value){
          d[key]=d[s]+value;
          _next.push_back(key);
        }
      }
    }
    next.clear();
    copy(_next.begin(),_next.end(),back_inserter(next));
  }
  return d[goal];
}
