#include <iostream>
using namespace std;

int main(void){
    int n,m;
    cin>>n;
    cin>>m;
    int in,out;
    int Smax=0;
    bool error = false;
    for(int i=0;i<n;i++){
      cin>>in>>out;
      Smax = max(Smax,m);
      m+=in;
      m-=out;
      if(m<0){
        error = true;
      }
    }
    Smax = max(Smax,m);
    if(error){
      cout<<0<<endl;
    }
    else{
      cout<<Smax<<endl;
    }
    return 0;
}
