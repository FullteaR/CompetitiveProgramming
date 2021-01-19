#include <iostream>
#include <cassert>
#include <map>
#define INF 100000000010
using namespace std;

int main(void){
  long N,K;
  cin>>N>>K;
  long* a = new long[N+1];
  for(long i=0;i<N;i++){
    cin>>a[i];
  }
  a[N]=0;
  map<long, long> mp;
  for(long i=1;i<=K;i++){
    mp[i]=0;
  }

  long i=0;
  long j=0;
  long count=0;
  long length=INF;
  while(i<N+1){
    assert(i<=j);
    if(count==K){
      length=min(length, j-i);
    }

    if(j==N or count==K){
      if(1<=a[i] and a[i]<=K){
        mp[a[i]]--;
        if(mp[a[i]]==0){
          count--;
        }
      }
      i++;
    }
    else{
      if(1<=a[j] and a[j]<=K){
        if(mp[a[j]]==0){
          count++;
        }
        mp[a[j]]++;
      }
      j++;
    }
  }

  if(length==INF){
    length=0;
  }
  cout<<length<<endl;

  return 0;
}
