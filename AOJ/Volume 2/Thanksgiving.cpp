#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int n,m;
  while(1){
    cin>>n>>m;
    if(n==0 and m==0){return 0;}
    vector<int> v;
    v.clear();
    for(int i=0;i<n;i++){
      int tmp;
      cin>>tmp;
      v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    int retval=0;
    for(int i=0;i<n;i++){
      if(i%m==n%m){
        continue;
      }
      retval+=v[i];
    }
    cout<<retval<<endl;
  }
}
