#include <iostream>
using namespace std;

int min(int a, int b);

int main(void){
  int n,m;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++){
    cin>>A[i];
  }
  cin>>m;
  int B[m];
  for(int i=0;i<m;i++){
    cin>>B[i];
  }

  for(int i=0;i<min(n,m);i++){
    if(A[i]<B[i]){
      cout<<1<<endl;
      return 0;
    }
    else if(A[i]>B[i]){
      cout<<0<<endl;
      return 0;
    }
  }

  if(min(n,m)==m){
    cout<<0<<endl;
  }
  else{
    cout<<1<<endl;
  }
  return 0;


}


int min(int a,int b){
  if(a<b){
    return a;
  }
  else{
    return b;
  }
}
