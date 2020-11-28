#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    int K,P;
    cin>>K>>P;
    int mod = K%P;
    if(mod==0){
      mod+=P;
    }
    cout<<mod<<endl;
  }
  return 0;
}
