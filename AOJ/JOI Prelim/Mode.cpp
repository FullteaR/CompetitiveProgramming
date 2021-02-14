#include <iostream>
#include <map>
using namespace std;


int main(void){
  int N,M;
  cin>>N>>M;
  map<int,int> mp;
  for(int i=0;i<=M;i++){
    mp[i]=0;
  }
  for(int i=0;i<N;i++){
    int A;
    cin>>A;
    mp[A]++;
  }
  int retval=0;
  for(int i=1;i<=M;i++){
    retval=max(mp[i], retval);
  }
  cout<<retval<<endl;
  return 0;
}
