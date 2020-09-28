#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int hit(string a, string r);
int blow(string a, string r);

int main(void){

  string a;
  string r;
  while(cin>>r>>a){
    if(r=="0" and a=="0"){
      return 0;
    }
    cout<<hit(a,r)<<" "<<blow(a,r)<<endl;
  }
}


int hit(string a, string r){
  int hit_count=0;
  for(int i=0;i<4;i++){
    if(a[i]==r[i]){
      hit_count++;
    }
  }
  return hit_count;
}
int blow(string a, string r){
  set<char> a_s,r_s,mul;
  for(int i=0;i<4;i++){
    a_s.insert(a[i]);
    r_s.insert(r[i]);
  }
  set_intersection(a_s.begin(),a_s.end(),r_s.begin(),r_s.end(),inserter(mul,mul.end()));
  return mul.size()-hit(a,r);
}
