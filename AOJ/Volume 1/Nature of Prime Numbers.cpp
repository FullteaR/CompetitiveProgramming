#include <iostream>

using namespace std;

void calc(int n);

int main(void){
  int n;
  while(true){
    cin>>n;
    if(n==0){break;}
    calc(n);
  }
  return 0;
}

void calc(int n){
  int mod[n];
  for(int i=0;i<n;i++){
    mod[i]=0;
  }
  for(int i=1;i<n;i++){
    mod[(i*i)%n]=1;
  }
  int retval[1+n/2];
  for(int i=0;i<=n/2;i++){
    retval[i]=0;
  }
  for(int i=0;i<n;i++){
    if(mod[i]==0){
      continue;
    }
    for(int j=i+1;j<n;j++){
      if(mod[j]==0){
        continue;
      }
      int d=j-i;
      if(d<0){
        d+=n;
      }
      if(d>n/2){
        d=n-d;
      }
      retval[d]++;
    }
  }
  for(int i=1;i<=n/2;i++){
    cout<<retval[i]*2<<endl;
  }
}
