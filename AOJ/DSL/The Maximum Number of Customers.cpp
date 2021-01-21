#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int main(void){
  long N,T;
  cin>>N>>T;
  map<long,long> in_map;
  map<long,long> out_map;
  vector<long> in_v;
  vector<long> out_v;
  for(long i=0;i<N;i++){
    long l,r;
    cin>>l>>r;
    if(in_map.find(l)==in_map.end()){
      in_map[l]=1;
    }
    else{
      in_map[l]++;
    }
    if(out_map.find(r)==out_map.end()){
      out_map[r]=1;
    }
    else{
      out_map[r]++;
    }
    in_v.push_back(l);
    out_v.push_back(r);
  }
  sort(in_v.begin(),in_v.end());
  in_v.erase(std::unique(in_v.begin(), in_v.end()), in_v.end());
  sort(out_v.begin(),out_v.end());
  out_v.erase(std::unique(out_v.begin(), out_v.end()), out_v.end());
  long counter=0;
  long retval=0;
  long i=0;
  long j=0;
  while(i<in_v.size()){
    if(in_v[i]<out_v[j]){
      counter+=in_map[in_v[i]];
      i++;
    }
    else if(in_v[i]>out_v[j]){
      counter-=out_map[out_v[j]];
      j++;
    }
    else{
      counter+=in_map[in_v[i]];
      i++;
      counter-=out_map[out_v[j]];
      j++;
    }
    retval = max(retval,counter);
  }
  cout<<retval<<endl;
  return 0;
}
