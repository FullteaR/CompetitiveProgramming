#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(void){
  int n;
  int id,m1,s1,m2,s2,m3,s3,m4,s4;
  int t;
  while(1){
    cin>>n;
    if(n==0)break;
    map<int,int> d;
    vector<int> v;
    for(int i=0;i<n;i++){
      cin>>id>>m1>>s1>>m2>>s2>>m3>>s3>>m4>>s4;
      t=60*(m1+m2+m3+m4)+s1+s2+s3+s4;
      v.push_back(t);
      d[t]=id;
    }
    sort(v.begin(),v.end());
    cout<<d[v[0]]<<endl;
    cout<<d[v[1]]<<endl;
    cout<<d[v[v.size()-2]]<<endl;
  }
  return 0;
}
