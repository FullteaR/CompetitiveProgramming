#include <iostream>
using namespace std;

long count(int b,int e,long k,long* A);

int main(void){
  int n,q;
  int b,e;
  long k;
  cin>>n;
  long A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>b>>e>>k;
    cout<<count(b,e,k,A)<<endl;
  }
  return 0;
}


long count(int b,int e,long k,long* A){
  long retval=0;
  for(int i=b;i<e;i++){
    if(A[i]==k){
      retval++;
    }
  }
  return retval;
}
