#include <iostream>
using namespace std;

int main(void){
  int n;
  while(1){
    cin>>n;
    if(n==0){break;}
    int ices[10];
    for(int i=0;i<10;i++){
      ices[i]=0;
    }
    int c;
    for(int i=0;i<n;i++){
      cin>>c;
      ices[c]++;
    }
    for(int i=0;i<10;i++){
      if(ices[i]==0){
        cout<<'-'<<endl;
      }
      else{
        for(int j=0;j<ices[i];j++){
          cout<<"*";
        }
        cout<<endl;
      }
    }
  }
  return 0;
}
