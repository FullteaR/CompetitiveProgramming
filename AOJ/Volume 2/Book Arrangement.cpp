#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string convert(long long n);

int main(void){
  long long A;
  while(cin>>A){
    if(A==0){break;}
    cout<<convert(A)<<endl;
  }
  return 0;
}

string convert(long long n){
  string retval="";
  while(n!=0){
    long long mod=n%10;
    while(mod<0){
      mod+=10;
    }
    retval+=mod+'0';
    n-=mod;
    n=n/(-10);
  }
  reverse(retval.begin(),retval.end());
  return retval;
}
