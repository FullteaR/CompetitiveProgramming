#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
  int* scores = new int[3];
  for(int i=0;i<3;i++){
    cin>>scores[i];
  }
  sort(scores, scores+3);
  cout<<scores[1]+scores[2]<<endl;
  return 0;
}
