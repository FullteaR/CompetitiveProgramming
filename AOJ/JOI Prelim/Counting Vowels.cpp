#include <iostream>
#include <map>
using namespace std;
int main(void){
  map<char,int> mp;
  for(int i=0;i<26;i++){
    mp['a'+i]=0;
  }
  int N;
  cin>>N;
  string S;
  cin>>S;
  for(int i=0;i<N;i++){
    mp[S[i]]++;
  }
  cout<<mp['a']+mp['i']+mp['u']+mp['e']+mp['o']<<endl;
  return 0;
}
