#include <iostream>
using namespace std;

int main(void){
  long X;
  cin>>X;
  long happy=0;
  happy+=(X/500)*1000;
  X=X%500;
  happy+=(X/5)*5;
  cout<<happy<<endl;
  return 0;
}
