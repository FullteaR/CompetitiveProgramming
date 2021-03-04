#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  long n;
  cin>>n;
  map<string, long> mp;
  vector<string> products;
  for(long i=0;i<n;i++){
    string S;
    long order;
    cin>>S>>order;
    if(mp.find(S)==mp.end()){
      mp[S]=order;
    }
    else{
      mp[S]+=order;
    }
    products.push_back(S);
  }
  sort(products.begin(),products.end(),[](string s, string t){
    if(s.size()==t.size()){
      return s<t;
    }
    else{
      return s.size()<t.size();
    }
  });
  products.erase(unique(products.begin(),products.end()),products.end());
  for(auto iter=products.begin();iter!=products.end();iter++){
    cout<<*iter<<" "<<mp[*iter]<<endl;
  }
  return 0;
}
