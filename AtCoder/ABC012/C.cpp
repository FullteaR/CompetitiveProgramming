#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int delta=2025-N;
  for(int i=1;i<=9;i++){
    if(delta%i==0 and delta/i<=9){
      cout<<i<<" x "<<delta/i<<endl;
    }
  }
  return 0;
}
