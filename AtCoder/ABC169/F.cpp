#include <iostream>
using namespace std;
#define mod 998244353

long long pow2(long long k);

int main(void){
  long long N,S;
  cin>>N>>S;
  long long A[N];
  //long long  table[N+1][N+1][S+1];
  long long ***table = new long long**[N+1];
  for (int i = 0; i < N+1; i++) {
    table[i] = new long long*[N+1];
    for (int j = 0; j < N+1; j++) {
        table[i][j] = new long long[S+1];
    }
  }

  for(long long i=0;i<N;i++){
    cin>>A[i];
  }
  //table[n][k][s]=A1~Anのうちでk個の和がsになる総数
  for(long long i=0;i<=N;i++){
    for(long long j=0;j<=N;j++){
      for(long long s=0;s<=S;s++){
        table[i][j][s]=0;
      }
      if(j<=i){
        table[i][j][0]=1;
      }
    }
  }
  for(long long n=1;n<=N;n++){
    for(long long k=0;k<=n;k++){
      for(long long s=0;s<=S;s++){
        table[n][k][s]=table[n-1][k][s];
        if(k>=1 and s>=A[n-1]){
          table[n][k][s]+=table[n-1][k-1][s-A[n-1]];
        }
      }
    }
  }
  long long retval=0;
  for(long long k=1;k<=N;k++){
    retval+=(table[N][k][S]*pow2(N-k));
    retval=retval%mod;
  }
  cout<<retval<<endl;
  return 0;
}

long long pow2(long long k){
  if(k==0){return 1;}
  if(k==1){return 2;}
  if(k%2==0){
    return (pow2(k/2)*pow2(k/2))%mod;
  }
  else{
    return (2*pow2(k-1))%mod;
  }
}
