#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  int N,A,B;
  cin>>N>>A>>B;
  char* S = new char[N+10];
  cin>>S;
  reverse(S+A-1,S+B);
  cout<<S<<endl;
  return 0;
}
