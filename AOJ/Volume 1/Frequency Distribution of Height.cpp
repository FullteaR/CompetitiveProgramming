#include <iostream>
using namespace std;

int main(void){
  int n;
  cin>>n;
  double h;
  int Dist[6]={0};
  for(int i=0;i<n;i++){
    cin>>h;
    if (h<165.0){
      Dist[0]+=1;
    }
    else if(h<170.0){
      Dist[1]+=1;
    }
    else if(h<175.0){
      Dist[2]+=1;
    }
    else if(h<180.0){
      Dist[3]+=1;
    }
    else if(h<185.0){
      Dist[4]+=1;
    }
    else{
      Dist[5]+=1;
    }
  }
  for(int i=0;i<6;i++){
    cout<<i+1<<":";
    for(int j=0;j<Dist[i];j++){
      cout<<"*";
    }
    cout<<endl;
  }
  return 0;
}
