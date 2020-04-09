#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define INF 1000010;

using namespace std;


int main(void){
  long c,n,m,s,d;
  while(true){
    cin>>c>>n>>m>>s>>d;
    if(c==0 and n==0 and m==0 and s==0 and d==0)break;
    d--;
    s--;

    long a,b,f;
    map<long,long> costs[n];
    for(int i=0;i<m;i++){
      cin>>a>>b>>f;
      a--;
      b--;
      costs[a][b]=f;
      costs[b][a]=f;
    }
    map<long,long> dist[n];
    for(long i=0;i<n;i++){
      for(long j=0;j<=c;j++){
        dist[i][j]=INF;
      }
    }
    dist[s][0]=0;

    vector<long> next,_next;
    next.push_back(s);
    while(next.empty()==false){
      _next.clear();
      for(auto iter=next.begin();iter!=next.end();iter++){
        long city=*iter;
        for(auto iter2=costs[city].begin();iter2!=costs[city].end();iter2++){
          long next_city=iter2->first;
          long fee=iter2->second;
          for(long ticket=0;ticket<=c;ticket++){
            if(dist[next_city][ticket]>dist[city][ticket]+fee){
              dist[next_city][ticket]=dist[city][ticket]+fee;
              _next.push_back(next_city);
            }
          }
          for(long ticket=1;ticket<=c;ticket++){
            if(dist[next_city][ticket]>dist[city][ticket-1]+fee/2){
              dist[next_city][ticket]=dist[city][ticket-1]+fee/2;
              _next.push_back(next_city);
            }
          }
        }
      }

      sort(_next.begin(),_next.end());
      _next.erase(unique(_next.begin(),_next.end()),_next.end());
      next.clear();
      copy(_next.begin(),_next.end(),back_inserter(next));

    }
    long retval=INF;
    for(long ticket=0;ticket<=c;ticket++){
        retval=min(dist[d][ticket],retval);
    }
    cout<<retval<<endl;
  }
  return 0;
}
