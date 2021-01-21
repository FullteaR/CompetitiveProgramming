#include <iostream>
#include <map>
using namespace std;

int main(void){
  long N,L;
  cin>>N>>L;
  long* a = new long[N];
  for(long i=0;i<N;i++){
    cin>>a[i];
  }
  map<long,long> d;
  for(long i=0;i<L;i++){
    if(d.find(a[i])==d.end()){
      d[a[i]]=1;
    }
    else{
      d[a[i]]++;
    }
  }
  cout<<d.begin()->first;
  for(long i=0;i+L<N;i++){
    d[a[i]]--;
    if(d[a[i]]==0){
      d.erase(a[i]);
    }
    if(d.find(a[i+L])==d.end()){
      d[a[i+L]]=1;
    }
    else{
      d[a[i+L]]++;
    }
    for(auto iter=d.begin();iter!=d.end();iter++){
      if(iter->second==0);
      else{
        cout<<" "<<iter->first;
        break;
      }
    }
  }
  cout<<endl;

  return 0;
}
