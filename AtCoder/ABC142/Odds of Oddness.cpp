#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  double odd=0;
  for(int i=1;i<=N;i++){
    if(i%2==1){
      odd+=1;
    }
  }
  cout<<odd/N<<endl;
  return 0;
}
