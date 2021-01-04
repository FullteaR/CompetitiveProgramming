#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

void enu(long i, set<long>* b);

int main(void){
  int n;
  cin>>n;
  int k;
  cin>>k;
  set<long> b;
  b.clear();
  for(int i=0;i<k;i++){
    int tmp;
    cin>>tmp;
    b.insert(tmp);
  }
  for(long i=0;i<pow(2,n);i++){
    enu(i,&b);
  }
}


void enu(long i, set<long>* b){
  set<long> d;
  d.clear();
  long j=0;
  long i_origin=i;
  while(i>0){
    if(i%2==1){
      d.insert(j);
    }
    i=i/2;
    j++;
  }
  for(auto iter=b->begin();iter!=b->end();iter++){
    if(d.find(*iter)==d.end()){
      return;
    }
  }
  printf("%ld:",i_origin);
  for(auto iter=d.begin();iter!=d.end();iter++){
    printf(" %ld",*iter);
  }
  printf("\n");
}
