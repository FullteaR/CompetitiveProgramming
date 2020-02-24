#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


int main(void){
  int n;
  cin>>n;
  string s;
  for(int i=0;i<n;i++){
    cin>>s;
    vector<char> c;
    for(int j=0;j<8;j++){
      c.push_back(s[j]);
    }
    sort(c.begin(),c.end());
    int Max=0;
    int Min=0;
    for(int j=0;j<8;j++){
      Max+=(int)(c[j]-'0')*pow(10,j);
      Min+=(int)(c[j]-'0')*pow(10,7-j);
    }
    cout<<Max-Min<<endl;
  }
  return 0;
}
