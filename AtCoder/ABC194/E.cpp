#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main(void){
  long N,M;
  cin>>N>>M;
  long* A = new long[N];
  for(long i=0;i<N;i++){
    cin>>A[i];
  }
  set<long> not_include;
  map<long,long> d;
  for(long i=0;i<N+10;i++){
    d[i]=0;
  }
  for(long i=0;i<M;i++){
    d[A[i]]++;
  }
  for(long i=0;i<N+10;i++){
    if(d[i]>0){
      ;
    }
    else{
      not_include.insert(i);
    }
  }


  long retval = *(not_include.begin());
  for(long i=0;i<N-M;i++){
    if(A[i]==A[i+M]){
      continue;
    }

    d[A[i]]--;
    if(d[A[i]]==0){
      not_include.insert(A[i]);
    }
    d[A[i+M]]++;
    if(d[A[i+M]]==1){
      not_include.erase(A[i+M]);
    }
    retval=min(retval,*(not_include.begin()));
  }
  cout<<retval<<endl;
}
