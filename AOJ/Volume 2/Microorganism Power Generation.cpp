#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int main(void){
  long M,W;
  while(cin>>M>>W){
    if(M==0 and W==0){
      break;
    }
    long* b1 = new long[M];
    for(int i=0;i<M;i++){
      cin>>b1[i];
    }
    sort(b1,b1+M);
    long* b2 = new long[W];
    for(int i=0;i<W;i++){
      cin>>b2[i];
    }
    sort(b2,b2+W);
    long* bw = new long[max(M,W)];
    long* bm = new long[min(M,W)];
    if(W>M){
      for(int i=0;i<W;i++){
        bw[i]=b2[i];
      }
      for(int i=0;i<M;i++){
        bm[i]=b1[i];
      }
    }
    else{
      for(int i=0;i<W;i++){
        bm[i]=b2[i];
      }
      for(int i=0;i<M;i++){
        bw[i]=b1[i];
      }
    }

    if(M>W){
      auto tmp=W;
      W=M;
      M=tmp;
    }
    assert(W>=M);


    long retval=0;
    do{
      long _retval=0;
      for(int i=0;i<min(M,W);i++){
        _retval+=abs(bm[i]-bw[i])*(abs(bm[i]-bw[i])-30)*(abs(bm[i]-bw[i])-30);
      }
      retval=max(retval,_retval);
    } while(next_permutation(bw, bw+W));
    cout<<retval<<endl;
  }
  return 0;
}
