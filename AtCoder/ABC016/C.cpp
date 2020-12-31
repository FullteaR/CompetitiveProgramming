#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;


int main(void){
  int N,M;
  cin>>N>>M;
  auto v = new vector<int>[N];
  for(int i=0;i<N;i++){
    v[i].clear();
  }
  for(int i=0;i<M;i++){
    int A,B;
    cin>>A>>B;
    v[A-1].push_back(B-1);
    v[B-1].push_back(A-1);
  }

  for(int i=0;i<N;i++){
    set<int> friends_friends;
    set<int> friends;
    set<int> diff;
    friends.clear();
    friends.insert(i);
    friends_friends.clear();
    diff.clear();
    for(auto iter=v[i].begin();iter!=v[i].end();iter++){
      friends.insert(*iter);
      for(auto iter2=v[*iter].begin();iter2!=v[*iter].end();iter2++){
        friends_friends.insert(*iter2);
      }
    }
    set_difference(friends_friends.begin(),friends_friends.end(),friends.begin(),friends.end(),inserter(diff,diff.end()));
    cout<<diff.size()<<endl;

  }
  return 0;
}
