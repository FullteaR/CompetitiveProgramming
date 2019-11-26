#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
  int N;
  char S[10010];
  cin>>N;
  cin>>S;
  for(int i=0;S[i]!=0;i++){
    S[i]=(S[i]-'A'+N)%26+'A';
  }
  cout<<S<<endl;
}
