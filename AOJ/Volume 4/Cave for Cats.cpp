#include <iostream>
#include <stack>
using namespace std;

int main(void){
  long L;
  cin>>L;
  stack<long> s;
  bool* in_cats = new bool[101];
  for(long i=0;i<=10;i++){
    in_cats[i]=false;
  }
  for(long i=0;i<L;i++){
    long c;
    cin>>c;
    if(c>0){
      if(in_cats[c]==false){
        in_cats[c]=true;
        s.push(c);
      }
      else{
        cout<<i+1<<endl;
        return 0;
      }
    }
    else{
      if(s.empty()){
        cout<<i+1<<endl;
        return 0;
      }
      c=-1*c;
      if(s.top()==c){
        s.pop();
        in_cats[c]=false;
      }
      else{
        cout<<i+1<<endl;
        return 0;
      }
    }
  }
  cout<<"OK"<<endl;
  return 0;
}
