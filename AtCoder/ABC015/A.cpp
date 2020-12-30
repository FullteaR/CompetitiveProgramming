#include <iostream>
using namespace std;

int main(void){
  string A,B;
  cin>>A;
  cin>>B;
  if(A.size()<B.size()){
    cout<<B<<endl;
  }
  else{
    cout<<A<<endl;
  }
  return 0;
}
