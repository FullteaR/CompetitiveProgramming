#include <iostream>
#include <math.h>
using namespace std;

int count(int* flags);
unsigned long decode(int* flags);

int main(void){
  int flags[64];
  for(int i=0;i<64;i++){
    flags[i]=0;
  }
  int q;
  cin>>q;
  int query,i;
  for(int j=0;j<q;j++){
    cin>>query;
    if(query==0){
      cin>>i;
      cout<<flags[i]<<endl;
    }
    else if(query==1){
      cin>>i;
      flags[i]=1;
    }
    else if(query==2){
      cin>>i;
      flags[i]=0;
    }
    else if(query==3){
      cin>>i;
      flags[i]=1-flags[i];
    }
    else if(query==4){
      if(count(flags)==64){
        cout<<1<<endl;
      }
      else{
        cout<<0<<endl;
      }
    }
    else if(query==5){
      if(count(flags)>0){
        cout<<1<<endl;
      }
      else{
        cout<<0<<endl;
      }
    }
    else if(query==6){
      if(count(flags)==0){
        cout<<1<<endl;
      }
      else{
        cout<<0<<endl;
      }
    }
    else if(query==7){
      cout<<count(flags)<<endl;
    }
    else if(query==8){
      cout<<decode(flags)<<endl;
    }
  }
  return 0;
}

int count(int* flags){
  int retval=0;
  for(int i=0;i<64;i++){
    retval+=flags[i];
  }
  return retval;
}

unsigned long decode(int* flags){
  unsigned long retval=0;
  for(int i=0;i<64;i++){
    retval+=((unsigned long)flags[i])*((unsigned long)pow(2,i));
  }
  return retval;
}
