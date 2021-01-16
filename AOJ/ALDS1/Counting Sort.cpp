#include <iostream>
using namespace std;

int main(void){
  long n;
  cin>>n;
  long* A = new long[n];
  long* B = new long[n];
  long k=10010;
  long* C = new long[k];
  for(long i=0;i<n;i++){
    cin>>A[i];
    B[i]=0;
  }
  for(long i=0;i<k;i++){
    C[i]=0;
  }
  for(long j=0;j<n;j++){
    C[A[j]]++;
  }
  for(long i=1;i<k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(long j=n-1;j>=0;j--){
    B[C[A[j]]-1]=A[j];
    C[A[j]]--;
  }
  for(long i=0;i<n;i++){
    cout<<B[i];
    if(i<n-1){
      cout<<" ";
    }
  }
  cout<<endl;
  return 0;
}
