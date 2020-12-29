#include <iostream>
using namespace std;

int main(void){
  int array[6]={1,2,3,4,5,6};
  long N;
  cin>>N;
  for(long i=0;i<N;i++){
    int tmp=array[i%5];
    array[i%5]=array[i%5+1];
    array[i%5+1]=tmp;
  }
  for(int i=0;i<6;i++){
    cout<<array[i];
  }
  cout<<endl;
  return 0;
}
