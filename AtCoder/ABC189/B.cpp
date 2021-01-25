#include <iostream>
using namespace std;

int main(void){
  long N,X;
  cin>>N>>X;
  X*=100;
  long total=0;
  for(int i=0;i<N;i++){
    long V,P;
    cin>>V>>P;
    total+=V*P;
    if(total>X){
      cout<<i+1<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}
