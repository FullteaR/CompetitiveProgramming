#include <iostream>
using namespace std;

int main(void){
  string s,t;
  cin>>s;
  cin>>t;
  long** table = new long* [s.size()+1];
  for(int i=0;i<(int)s.size()+1;i++){
    table[i]=new long[t.size()+1];
  }
  for(int i=0;i<(int)s.size()+1;i++){
    for(int j=0;j<(int)t.size()+1;j++){
      table[i][j]=0;
    }
  }

  for(int i=1;i<(int)s.size()+1;i++){
    for(int j=1;j<(int)t.size()+1;j++){
      table[i][j]= max(table[i-1][j], table[i][j-1]);
      if(s[i-1]==t[j-1]){
        table[i][j]=max(table[i][j], table[i-1][j-1]+1);
      }
    }
  }
  string retval="";
  int p=s.size();
  int q=t.size();
  while(p!=0 and q!=0){
    if(p>0 and table[p-1][q]==table[p][q]){
      p-=1;
    }
    else if(q>0 and table[p][q]==table[p][q-1]){
      q-=1;
    }
    else{
      retval=s[p-1]+retval;
      p-=1;
      q-=1;
    }
  }

  cout<<retval<<endl;
  return 0;
}
