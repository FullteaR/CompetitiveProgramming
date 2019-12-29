#include <iostream>
using namespace std;

void swap(int b, int e, int t, long* A);

int main(void){
  int n;
  cin>>n;
  long A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  int q;
  cin>>q;
  int b,e,t;
  for(int i=0;i<q;i++){
    cin>>b>>e>>t;
    swap(b,e,t,A);
  }
  for(int i=0;i<n-1;i++){
    cout<<A[i]<<" ";
  }
  cout<<A[n-1]<<endl;
  return 0;
}


void swap(int b,int e,int t,long* A){
  long tmp;
  for(int k=0;k<e-b;k++){
    tmp=A[t+k];
    A[t+k]=A[b+k];
    A[b+k]=tmp;
  }
}
