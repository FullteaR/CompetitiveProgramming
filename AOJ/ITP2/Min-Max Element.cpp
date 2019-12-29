#include <iostream>
using namespace std;

long min(int b,int e, long* A);
long max(int b,int e, long* A);

int main(void){
  int n,q;
  int com,b,e;
  cin>>n;
  long A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  cin>>q;
  for(int i=0;i<q;i++){
    cin>>com>>b>>e;
    if(com==0){
      cout<<min(b,e,A)<<endl;
    }
    else{
      cout<<max(b,e,A)<<endl;
    }
  }
  return 0;
}


long min(int b,int e,long* A){
  long retval=1000000010;
  for(int i=b;i<e;i++){
    if(retval>A[i]){
      retval=A[i];
    }
  }
  return retval;
}

long max(int b,int e,long* A){
  long retval=-1000000010;
  for(int i=b;i<e;i++){
    if(retval<A[i]){
      retval=A[i];
    }
  }
  return retval;
}
