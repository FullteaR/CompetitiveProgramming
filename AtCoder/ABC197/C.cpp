#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define INF pow(2,35);

int main(void){
  long long N;
  cin>>N;
  long long A[N];
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  vector<long long> splits;
  long long retval = INF;
  for(long long i=0;i<pow(2,N);i++){
    long long val=0;
    bool ope;
    splits.clear();
    long long _i = i;
    for(int j=0;j<N;j++){
      ope = ((_i%2)==0);
      _i = _i/2;
      if(ope){
        splits.push_back(val);
        val=A[j];
      }
      else{
        val = val | A[j];
      }
    }
    splits.push_back(val);
    long long _retval=0;
    for(int j=0;j<(int)splits.size();j++){
      _retval = _retval ^ splits[j];
    }
    retval = min(retval,_retval);
  }
  cout<<retval<<endl;
  return 0;
}
