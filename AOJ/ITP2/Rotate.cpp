#include <iostream>
using namespace std;

void rotate(int b, int e, int m, int n,long* A);

int main(void){
  int n;
  cin>>n;
  long A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  int q;
  cin>>q;
  int b,e,m;
  for(int i=0;i<q;i++){
    cin>>b>>m>>e;
    rotate(b,e,m,n,A);
  }
  for(int i=0;i<n-1;i++){
    cout<<A[i]<<" ";
  }
  cout<<A[n-1]<<endl;
  return 0;
}


void rotate(int b,int e,int m,int n,long* A){
  long tmp[n];
  for(int i=b;i<e;i++){
    tmp[i]=A[i];
  }
  for(int i=b;i<e;i++){
    A[b+((i-b+e-m)%(e-b))]=tmp[i];
  }
}
