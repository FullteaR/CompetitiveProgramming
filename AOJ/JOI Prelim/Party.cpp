#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main(void){
  long n,m;
  while(1){
    cin>>n;
    cin>>m;
    if(n==0 and m==0){
      return 0;
    }
    unordered_map<long, set<long> > mp;
    for(long i=1;i<=n;i++){
      mp[i].clear();
    }
    for(long i=0;i<m;i++){
      long a,b;
      cin>>a>>b;
      mp[a].insert(b);
      mp[b].insert(a);
    }

    set<long> invite;
    invite.clear();
    invite.insert(1);
    for(const auto &a : mp[1]){
      invite.insert(a);

      for(const auto &b : mp[a]){
        invite.insert(b);
      }
    }
    cout<<invite.size()-1<<endl;
  }
  return 0;
}
