#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int* x = new int[N];
  for(int i=0;i<N;i++){
    cin>>x[i];
  }
  int m=x[0];
  int M=x[0];
  for(int i=1;i<N;i++){
    m=min(m,x[i]);
    M=max(M,x[i]);
  }
  cout<<(M-m+1)/2<<endl;
  return 0;
}
