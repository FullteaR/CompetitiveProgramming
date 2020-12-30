#include <iostream>
#include <set>
using namespace std;


int main(void){
  set<int> s;
  int N,K;
  cin>>N>>K;
  for(int k=0;k<K;k++){
    int T;
    cin>>T;
    s.insert(T);
  }
  for(int n=1;n<N;n++){
    set<int> _s;
    for(int k=0;k<K;k++){
      int T;
      cin>>T;
      for(auto iter=s.begin(); iter!=s.end();iter++){
        _s.insert(T^(*iter));
      }
    }
    s.swap(_s);
    _s.clear();
  }
  for(auto iter=s.begin();iter!=s.end();iter++){
    if(*iter==0){
      cout<<"Found"<<endl;
      return 0;
    }
  }
  cout<<"Nothing"<<endl;
  return 0;
}
