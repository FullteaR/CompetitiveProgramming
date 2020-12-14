#include <iostream>
#include <cstdio>
using namespace std;


int main(void){
  long N,Q;
  cin>>N>>Q;
  long* A= new long[N];
  for(long i=0;i<N;i++){
    cin>>A[i];
  }
  long T,X,Y;
  for(int q=0;q<Q;q++){
    cin>>T>>X>>Y;
    if(T==1){
      A[X-1]=A[X-1]^Y;
    }
    else{
      long a=A[Y-1];
      for(long i=X-1;i<Y-1;i++){
        a=A[i]^a;
      }
      cout<<a<<endl;
    }
  }
}
