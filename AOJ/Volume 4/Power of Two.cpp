#include <iostream>
#include <cmath>
using namespace std;

int main(void){
  int N;
  cin>>N;
  for(int i=0;i<10000;i++){
    if(pow(2,i)<=N and N<pow(2,i+1)){
      cout<<pow(2,i)<<endl;
      break;
    }
  }
  return 0;
}
