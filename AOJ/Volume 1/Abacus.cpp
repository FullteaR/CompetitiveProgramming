#include <iostream>
using namespace std;

void abacus(int n);


int main(void){
  int n;
  bool st=true;
  while(cin>>n){
    if(st==false){
      cout<<endl;
    }
    abacus(n);
    st=false;
  }
  return 0;
}

void abacus(int n){
  int keta[5]={n/10000,(n%10000)/1000,(n%1000)/100,(n%100)/10,n%10};

  for(int i=0;i<5;i++){
    if(keta[i]>=5){
      cout<<" ";
    }
    else{
      cout<<"*";
    }
  }
  cout<<endl;

  for(int i=0;i<5;i++){
    if(keta[i]<5){
      cout<<" ";
    }
    else{
      cout<<"*";
      keta[i]-=5;
    }
  }
  cout<<endl;

  cout<<"====="<<endl;

  for(int i=0;i<5;i++){
    if(keta[i]==0){
      cout<<" ";
    }
    else{
      cout<<"*";
    }
  }
  cout<<endl;

  for(int i=0;i<5;i++){
    if(keta[i]==1){
      cout<<" ";
    }
    else{
      cout<<"*";
    }
  }
  cout<<endl;

  for(int i=0;i<5;i++){
    if(keta[i]==2){
      cout<<" ";
    }
    else{
      cout<<"*";
    }
  }
  cout<<endl;

  for(int i=0;i<5;i++){
    if(keta[i]==3){
      cout<<" ";
    }
    else{
      cout<<"*";
    }
  }
  cout<<endl;

  for(int i=0;i<5;i++){
    if(keta[i]==4){
      cout<<" ";
    }
    else{
      cout<<"*";
    }
  }
  cout<<endl;
}
