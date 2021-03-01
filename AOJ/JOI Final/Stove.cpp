#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  long N,K;
  cin>>N>>K;
  long* T = new long[N];
  long* diff = new long[N-1];
  for(long i=0;i<N;i++){
    cin>>T[i];
  }
  long retval=N;
  for(long i=0;i<N-1;i++){
    diff[i]=T[i+1]-(T[i]+1);
    retval+=diff[i];
  }
  sort(diff,diff+N-1);
  for(long i=0;i<K-1;i++){
    retval-=diff[N-2-i];
  }
  cout<<retval<<endl;
  return 0;
}
