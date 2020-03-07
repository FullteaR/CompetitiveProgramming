#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
#define length 800010

int main(void){
  char* S=(char*)malloc(sizeof(char)*length);
  string s;
  cin>>s;
  long left=length/2;
  long right=left+s.size()-1;
  for(int i=0;i<s.size();i++){
    S[length/2+i]=s[i];
  }
  int t,f;
  char c;
  int rev=0;
  int Q;
  cin>>Q;
  for(int i=0;i<Q;i++){
    cin>>t;
    if(t==1){
      rev++;
      rev=rev%2;
    }
    else{
      cin>>f>>c;
      if((f==1 and rev==0) || (f==2 and rev==1)){
        left--;
        S[left]=c;
      }
      else{
        right++;
        S[right]=c;
      }
    }
  }
  if(rev==0){
    for(long i=left;i<=right;i++){
      cout<<S[i];
    }
  }
  else{
    for(long i=right;i>=left;i--){
      cout<<S[i];
    }
  }
  cout<<endl;
  return 0;
}
