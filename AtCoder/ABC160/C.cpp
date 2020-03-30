#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void){
  long N,K;
  cin>>K>>N;
  vector<int> v;
  long _A[N];
  for(int i=0;i<N;i++){
    cin>>_A[i];
  }
  long M=-10000;
  for(int i=0;i<N;i++){
    M=max(min(abs(_A[(i+1)%N]-_A[i]),K-abs(_A[(i+1)%N]-_A[i])),M);
  }
  cout<<K-M<<endl;
}
