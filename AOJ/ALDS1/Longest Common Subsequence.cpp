//C++11
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int LCS(string s, string t);

int main(void){
  int n;
  string s;
  string t;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    cin>>t;
    cout<<LCS(s,t)<<endl;
  }
}

int LCS(string s, string t){
  int a[s.length()+1][t.length()+1];
  for(int i=0;i<s.length()+1;i++){
    for(int j=0;j<t.length()+1;j++){
      a[i][j]=0;
    }
  }
  char S,T;
  for(int i=1;i<s.length()+1;i++){
    for(int j=1;j<t.length()+1;j++){
      S=s[i-1];
      T=t[j-1];
      if(S!=T){
        a[i][j]=max({a[i-1][j-1],a[i-1][j],a[i][j-1]});
      }
      else{
        a[i][j]=max({a[i-1][j-1]+1,a[i-1][j],a[i][j-1]});
      }
    }
  }
  return a[s.length()][t.length()];
}
