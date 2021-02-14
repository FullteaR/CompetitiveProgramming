#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
  vector<int> C;
  C.clear();
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N+M;i++){
    int tmp;
    cin>>tmp;
    C.push_back(tmp);
  }
  sort(C.begin(),C.end());
  for(int i=0;i<N+M;i++){
    cout<<C[i]<<endl;
  }
  return 0;
}
