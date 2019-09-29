#include <iostream>
using namespace std;

int main(void){
  int A,B;
  cin>>A>>B;
  int socket=1;
  int ans=0;
  while(socket<B){
    ans+=1;
    socket+=(A-1);
  }
  cout<<ans<<endl;
  return 0;
}
