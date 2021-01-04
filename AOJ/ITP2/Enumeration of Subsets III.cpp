#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

int main(void){
  int n;
  cin>>n;
  int k;
  cin>>k;
  vector<long> b;
  b.clear();
  for(int i=0;i<k;i++){
    int tmp;
    cin>>tmp;
    b.push_back(tmp);
  }
  for(long i=0;i<pow(2,k);i++){
    long j=i;
    long M=0;
    vector<long> d;
    d.clear();
    long ind=0;
    while(j>0){
      if(j%2==1){
        M+=pow(2,b[ind]);
        d.push_back(b[ind]);
      }
      j=j/2;
      ind++;
    }
    printf("%ld:",M);
    for(auto iter=d.begin();iter!=d.end();iter++){
      printf(" %ld",*iter);
    }
    printf("\n");
  }
}
