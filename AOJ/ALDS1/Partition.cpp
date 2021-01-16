#include <iostream>
using namespace std;

int main(void){
  long n;
  cin>>n;
  long* A = new long[n];
  for(long i=0;i<n;i++){
    cin>>A[i];
  }
  long p=0;
  long r=n-1;
  long x=A[r];
  long i=p-1;
  for(long j=p;j<=r-1;j++){
    if(A[j]<=x){
      i++;
      long tmp=A[i];
      A[i]=A[j];
      A[j]=tmp;
    }
  }
  long tmp=A[i+1];
  A[i+1]=A[r];
  A[r]=tmp;
  for(long j=0;j<n;j++){
    if(j==i+1){
      cout<<"["<<A[j]<<"]";
    }
    else{
      cout<<A[j];
    }
    if(j<n-1){
      cout<<" ";
    }
  }
  cout<<endl;
  return 0;
}
