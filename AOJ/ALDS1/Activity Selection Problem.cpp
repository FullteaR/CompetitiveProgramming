#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<long,long> a, pair<long,long> b){
  if(b.second==a.second){
    return a.first<b.first;
  }
  else{
    return a.second<b.second;
  }
}


int main(void){
  long n;
  cin>>n;
  vector< pair<long,long> > times;
  long _s,_t;
  long Max_S=0;
  for(long i=0;i<n;i++){
    cin>>_s>>_t;
    times.push_back(make_pair(_s,_t));
    Max_S=max(Max_S,_s);
  }
  sort(times.begin(),times.end(),comp);

  long retval=0;
  long t=0;
  for(long i=0;i<n;i++){
    if(times[i].first<=t){
      ;
    }
    else{
      t=times[i].second;
      retval++;
    }
  }
  cout<<retval<<endl;

  return 0;
}
