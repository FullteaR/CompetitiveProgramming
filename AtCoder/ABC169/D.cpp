#include <iostream>
#include <cmath>
using namespace std;

int main(void){
  long long N;
  cin>>N;
  bool* primes=(bool*)malloc((long long)sqrt(N+1)*sizeof(bool));
  for(long long i=0;i<=10;i++){
    primes[i]=true;
  }
  primes[0]=false;
  primes[1]=false;
  for(long long i=0;i<sqrt(N)+10;i++){
    if(primes[i]==false){continue;}
    long long k=2;
    while(k*i<=N){
      primes[k*i]=false;
      k++;
    }
  }
  return 0;
}
