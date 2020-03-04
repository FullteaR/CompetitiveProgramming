#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct bridge{
  int a;
  int b;
  int cost;
  bool operator<(const bridge &another) const{
    return cost<another.cost;
  };
};

int main(void){
  int n,m;
  int a,b,cost;
  int retval;
  while(1){
    cin>>n>>m;
    retval=0;
    if(n==0 and m==0)break;
    vector<bridge> bridges;
    for(int i=0;i<m;i++){
      bridge bri;
      cin>>a>>b>>cost;
      bri.a=a;
      bri.b=b;
      bri.cost=cost;
      bridges.push_back(bri);
    }
    sort(bridges.begin(),bridges.end());
    int city[n];
    for(int i=0;i<n;i++){
      city[i]=i;
    }
    for(int i=0;i<m;i++){
      bridge bri=bridges[i];
      if(city[bri.a]==city[bri.b]){
        continue;
      }
      else{
        retval+=bri.cost;
        int group=city[bri.b];
        for(int j=0;j<n;j++){
          if(city[j]==group){
            city[j]=city[bri.a];
          }
        }
      }
    }
    cout<<retval<<endl;
  }
  return 0;
}
