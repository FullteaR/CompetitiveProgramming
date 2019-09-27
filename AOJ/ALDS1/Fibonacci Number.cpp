#include <iostream>

using namespace std;

int main(void){
  int n;
  cin>>n;
  int A[50];
  for(int i=0;i<50;i++){
    A[i]=0;
  }
  A[0]=1;
  A[1]=1;
  for(int i=2;i<=n;i++){
    A[i]=A[i-1]+A[i-2];
  }
  cout<<A[n]<<endl;
  return 0;
}
