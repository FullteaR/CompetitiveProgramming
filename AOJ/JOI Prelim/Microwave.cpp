#include <iostream>
using namespace std;

int main(void){
  int A,B,C,D,E;
  cin>>A>>B>>C>>D>>E;
  int t;
  if(A>0){
    t=(B-A)*E;
  }
  else{
    t=(-A*C)+D+E*B;
  }
  cout<<t<<endl;
  return 0;
}
