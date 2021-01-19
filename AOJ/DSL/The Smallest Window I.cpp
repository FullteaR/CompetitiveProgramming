#include <iostream>
#include <cassert>
#define INF 100000000010
using namespace std;

int main(void){
  long N,S;
  cin>>N>>S;
  long* a = new long[N+1];
  for(long i=0;i<N;i++){
    cin>>a[i];
  }
  a[N]=0;
  long i=0;
  long j=0;
  long sum=0;
  long length=INF;
  while(i<N+1){
    assert(i<=j);
    if(sum>=S){
      length=min(length, j-i);
    }

    if(j==N or sum>=S){
      sum-=a[i];
      i++;
    }
    else{
      sum+=a[j];
      j++;
    }
  }

  if(length==INF){
    length=0;
  }
  cout<<length<<endl;

  return 0;
}
