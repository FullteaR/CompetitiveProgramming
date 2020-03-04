#include <iostream>
using namespace std;

int hamming(int n);

int main(void){
  int m,n;
  int retval;
  int hammingList[1000001];
  for(int i=0;i<=1000000;i++){
    hammingList[i]=hamming(i);
  }

  while(cin>>m>>n){
    retval=0;
    for(int i=m;i<=n;i++){
      retval+=hammingList[i];
    }
    cout<<retval<<endl;
  }
  return 0;
}

int hamming(int n){
  while(n>1){
    if((n/2)*2==n){
      n=n/2;
    }
    else{
      break;
    }
  }
  while(n>1){
    if((n/3)*3==n){
      n=n/3;
    }
    else{
      break;
    }
  }
  while(n>1){
    if((n/5)*5==n){
      n=n/5;
    }
    else{
      break;
    }
  }
  if(n==1) return 1;
  else return 0;
}
