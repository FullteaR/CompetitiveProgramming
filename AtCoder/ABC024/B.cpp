#include <iostream>
using namespace std;
int main(void){
  long N,T;
  cin>>N>>T;
  long total=0;
  long* A = new long [N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  for(int i=0;i<N-1;i++){
    total+=min(T,A[i+1]-A[i]);
  }
  total+=T;
  cout<<total<<endl;
  return 0;
}
