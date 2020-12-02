#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long search(vector<long>* h1, long val, long T);

int main(void){
  long N,T;
  cin>>N>>T;
  long * A = new long[N];
  for(long i=0;i<N;i++){
    cin>>A[i];
  }
  vector<long> h1;
  h1.clear();
  for(long bit=0;bit<pow(2,N/2);bit++){
    long bit_tmp = bit;
    long val=0;
    long index=0;
    while(bit_tmp>0){
      if(bit_tmp%2==1){
        val+=A[index];
      }
      index++;
      bit_tmp=bit_tmp/2;
    }
    h1.push_back(val);
  }

  sort(h1.begin(),h1.end());
  vector<long> h2;
  for(long i=N/2;i<N;i++){
    h2.push_back(A[i]);
  }
  long retval=0;
  for(long bit=0;bit<pow(2,h2.size());bit++){
    long bit_tmp = bit;
    long val=0;
    long index=0;
    while(bit_tmp>0){
      if(bit_tmp%2==1){
        val+=h2[index];
      }
      index++;
      bit_tmp=bit_tmp/2;
    }
    retval=max(retval, search(&h1,val,T));
  }
  cout<<retval<<endl;
  return 0;
}

long search(vector<long>* h1, long val, long T){
  long m=0;
  long M=h1->size()-1;
  long mid=(m+M)/2;
  while(M-m>1){
    if((*h1)[mid]+val==T){
      return T;
    }
    if((*h1)[mid]+val<T){
      m=mid;
    }
    else{
      M=mid;
    }
    mid=(M+m)/2;
  }
  for(long i=M;i>=m;i--){
    if((*h1)[i]+val<=T){
      return (*h1)[i]+val;
    }
  }
  return 0;
}
