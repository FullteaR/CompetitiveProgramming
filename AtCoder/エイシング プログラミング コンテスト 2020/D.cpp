#include <iostream>
using namespace std;

long long f(long long n);
long long popcount(long long n);
long long pow2(long long i, long long mod);

int main(void){
  long long* cache =(long long*)malloc(sizeof(long long)*200010);
  for(long long i=0;i<200010;i++){
    cache[i]=f(i);
  }

  long long N;
  string _X;
  cin>>N;
  cin>>_X;
  int* X = (int*)malloc(sizeof(int)*N);
  for(int i=0;i<N;i++){
    if(_X[i]=='1'){
      X[i]=1;
    }
    else{
      X[i]=0;
    }
  }
  long long pc=0;
  long long Xiplus=0;
  long long Ximinus=0;
  for(long long i=0;i<N;i++){
    pc+=X[i];
  }
  for(long long i=0;i<N;i++){
    Xiplus+=X[N-i-1]*pow2(i,pc+1);
    Xiplus=Xiplus%(pc+1);
    Ximinus+=X[N-i-1]*pow2(i,pc-1);
    Ximinus=Ximinus%(pc-1);
  }
  for(long long i=0;i<N;i++){
    long long Xi=0;
    if(X[i]==1){
      Xi=Ximinus;
      Xi-=pow2(N-i-1,pc-1);
      Xi=Xi%(pc-1);
    }
    else{
      Xi=Xiplus;
      Xi+=pow2(N-i-1,pc+1);
      Xi=Xi%(pc+1);
    }
    cout<<cache[Xi]+1<<endl;
  }
}

long long f(long long n){
  if(n==0){
    return 0;
  }
  else{
    return 1+f(n%popcount(n));
  }
}

long long popcount(long long n){
  long long retval=0;
  while(n>0){
    if(n%2==1){
      retval+=1;
    }
    n=n/2;
  }
  return retval;
}


long long pow2(long long i, long long mod){
  if(i==0){
    return 1;
  }
  else if(i==1){
    return 2;
  }

  if(i%2==1){
    return (2*pow2(i-1,mod))%mod;
  }
  else{
    return (pow2(i/2,mod)*pow2(i/2,mod))%mod;
  }
}
