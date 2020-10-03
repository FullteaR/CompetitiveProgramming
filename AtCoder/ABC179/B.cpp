#include <iostream>

using namespace std;

int main(void){
  int N;
  cin>>N;
  int count = 0;
  for(int i=0;i<N;i++){
    int D1, D2;
    cin>>D1>>D2;
    if(D1==D2){
      count++;
      if(count>=3){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
    else{
      count=0;
    }
  }
  cout<<"No"<<endl;
}
