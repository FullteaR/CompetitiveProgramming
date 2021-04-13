#include <iostream>
using namespace std;
int main(void){
  long N;
  cin>>N;
  if(N==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  while(N%10==0){
    N = N/10;
  }
  string S = to_string(N);
  for(long i=0;i<S.size()/2+1;i++){
    if(S[i]!=S[S.size()-i-1]){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}
