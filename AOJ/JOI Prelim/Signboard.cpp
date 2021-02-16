#include <iostream>
using namespace std;

bool is_able_make(string old, string _new);

int main(void){
  int N;
  cin>>N;
  string signboard;
  cin>>signboard;
  int retval = 0;
  for(int i=0;i<N;i++){
    string old;
    cin>>old;
    if(is_able_make(old, signboard)){
      retval++;
    }
  }
  cout<<retval<<endl;
  return 0;
}

bool is_able_make(string old, string _new){
  for(int i=0;i<old.size();i++){
    if(old[i]!=_new[0])continue;
    for(int j=i+1;j<old.size();j++){
      if(old[j]!=_new[1]){
        continue;
      }
      int diff=j-i;
      bool flag=true;
      for(int k=2;k<_new.size();k++){
        if(i+diff*k>=old.size() or old[i+diff*k]!=_new[k]){
          flag = false;
          break;
        }
      }
      if(flag){
        return true;
      }
    }
  }
  return false;
}
