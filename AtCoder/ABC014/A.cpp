#include <iostream>
using namespace std;
int main(void){
  int a,b;
  cin>>a;
  cin>>b;
  cout<<(b-(a%b))%b<<endl;
}
