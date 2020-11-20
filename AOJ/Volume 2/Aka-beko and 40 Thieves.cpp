#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(void){
  map<char, pair<char, char> > d;
  d['A'] = make_pair('X','Y');
  d['X'] = make_pair('N','Z');
  d['Y'] = make_pair('X','N');
  d['Z'] = make_pair('W','B');
  d['W'] = make_pair('B','Y');
  d['B'] = make_pair('Y','X');
  d['N'] = make_pair('N','N');
  string p;
  while(cin>>p){
    if(p=="#"){return 0;}
    char city='A';
    for(int i=0;i<p.length();i++){
      char c=p[i];
      if(c=='0'){
        city=d[city].first;
      }
      else{
        city=d[city].second;
      }
    }
    if(city=='B'){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  }
}
