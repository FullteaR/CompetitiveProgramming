#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  int N,K;
  cin>>N>>K;
  vector<int> R;
  int r;
  for(int i=0;i<N;i++){
    cin>>r;
    R.push_back(r);
  }
  sort(R.begin(),R.end());
  double score=0;
  for(int i=N-K;i<N;i++){
    score=(R[i]+score)/2;
  }
  printf("%.16f\n",score);
  return 0;
}
