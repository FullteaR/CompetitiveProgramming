#include <iostream>
using namespace std;

int main(void){
  int A,B;
  int K2;
  cin>>A>>B;
  K2=A+B;
  if(K2%2==0){
    cout<<K2/2<<endl;
  }
  else{
    cout<<"IMPOSSIBLE"<<endl;
  }
}
