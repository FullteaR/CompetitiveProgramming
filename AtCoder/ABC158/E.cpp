#include <iostream>
#include <map>
using namespace std;
long long pow(long long i, long long P);

int main(void){
  long N,P;
  string _S;
  cin>>N>>P;
  cin>>_S;


  if(P==2 or P==5){
    long long retval=0;
    for(long long i=0;i<N;i++){
      if((_S[i]-'0')%P==0){
        retval+=(i+1);
      }
    }
    cout<<retval<<endl;
    return 0;
  }



  map<long long,long long>d;
  for(long long i=0;i<P;i++){
    d[i]=0;
  }
  d[0]=1;
  long long S=0;
  for(long long i=0;i<N;i++){
    S+=pow(i+1,P)*(_S[N-i-1]-'0');
    d[S%P]=d[S%P]+1;
  }
  long long retval=0;
  for(long long i=0;i<P;i++){
    if(d[i]>0){
      retval+=(d[i]-1)*d[i]/2;
    }
  }
  cout<<retval<<endl;
  return 0;
  return 0;
}

long long pow(long long i,long long P){
  if(i==0) return 1;
  else if(i%2==0){
    return (pow(i/2,P)*pow(i/2,P))%P;
  }
  else{
    return (10*pow(i-1,P))%P;
  }
}
