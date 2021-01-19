#include <iostream>
#include <cassert>
using namespace std;

int main(void){
  int N,Q;
  cin>>N>>Q;
  long* a = new long[N];
  long* x = new long[Q];
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  for(int i=0;i<Q;i++){
    cin>>x[i];
  }
  long* cum = new long[N+1];
  cum[0]=0;
  for(int i=0;i<N;i++){
    cum[i+1]=cum[i]+a[i];
  }
  for(int i=0;i<Q;i++){
    long count=0;
    for(int r=0;r<N+1;r++){
      long max=r;
      long min=0;
      while(max-min>2){
        long mid=(min+max)/2;
        if(cum[r]-cum[mid]<=x[i]){
          max=mid;
        }
        else{
          min=mid;
        }
      }
      for(long j=min;j<=max;j++){
        if(cum[r]-cum[j]<=x[i]){
          count+=r-j;
          break;
        }
      }
    }
    cout<<count<<endl;
  }
  return 0;
}
