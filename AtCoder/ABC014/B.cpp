#include <iostream>
using namespace std;
int main(void){
  int n;
  long X;
  cin>>n>>X;
  long* a = new long[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  long cost=0;
  for(int i=0;i<n;i++){
    if(X%2==1){
      cost+=a[i];
    }
    X=X/2;
  }
  cout<<cost<<endl;
}
