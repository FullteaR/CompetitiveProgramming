#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  long L[N];
  for(int i=0;i<N;i++){
    cin>>L[i];
  }
  long retval=0;
  for(int i=0;i<N;i++){
    long a=L[i];
    for(int j=i+1;j<N;j++){
      long b=L[j];
      for(int k=j+1;k<N;k++){
        long c=L[k];
        if(a+b>c and b+c>a and c+a>b and a!=b and b!=c and c!=a){
          retval++;
        }
      }
    }
  }
  cout<<retval<<endl;
  return 0;
}
