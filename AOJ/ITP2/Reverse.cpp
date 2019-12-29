#include <iostream>
using namespace std;

void reverse(int b, int e, long* A);

int main(void){
  int n;
  cin>>n;
  long A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  int q;
  cin>>q;
  int b,e;
  for(int i=0;i<q;i++){
    cin>>b>>e;
    reverse(b,e,A);
  }
  for(int i=0;i<n-1;i++){
    cout<<A[i]<<" ";
  }
  cout<<A[n-1]<<endl;
  return 0;
}


void reverse(int b,int e,long* A){
  long tmp[e-b+1];
  for(int i=b;i<e;i++){
    tmp[i-b]=A[i];
  }
  for(int i=b;i<e;i++){
    A[i]=tmp[e-i-1];
  }
}
