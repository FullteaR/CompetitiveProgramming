#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main(void){
  int n;
  cin>>n;
  auto ope = new pair<int, char>[2*n];
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    ope[2*i]=make_pair(a,'+');
    ope[2*i+1]=make_pair(b,'-');
  }
  sort(ope,ope+2*n);

  int buy=0;
  int retval=0;
  for(int i=0;i<2*n;i++){
    if(ope[i].second=='+'){
      buy++;
      retval=max(retval,buy);
    }
    else{
      buy--;
    }
  }
  cout<<retval<<endl;

  return 0;
}
