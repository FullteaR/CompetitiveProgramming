#include <iostream>
#include <math.h>
using namespace std;

int count(int* bit, int* mask);
int masksum(int* mask);
unsigned long decode(int* bit, int* mask);

int main(void){
  int n;
  cin>>n;
  int mask[n][64];
  int bit[64];
  for(int i=0;i<n;i++){
    for(int j=0;j<64;j++){
      mask[i][j]=0;
    }
  }
  for(int i=0;i<64;i++){
    bit[i]=0;
  }
  int k;
  int b;
  for(int i=0;i<n;i++){
    cin>>k;
    for(int j=0;j<k;j++){
      cin>>b;
      mask[i][b]=1;
    }
  }
  int q;
  cin>>q;
  int query,m;
  for(int i=0;i<q;i++){
    cin>>query>>m;
    if(query==0){
      cout<<bit[m]<<endl;
    }
    else if(query==1){
      for(int j=0;j<64;j++){
        if(mask[m][j]==1){
          bit[j]=1;
        }
      }
    }
    else if(query==2){
      for(int j=0;j<64;j++){
        if(mask[m][j]==1){
          bit[j]=0;
        }
      }
    }
    else if(query==3){
      for(int j=0;j<64;j++){
        if(mask[m][j]==1){
          bit[j]=1-bit[j];
        }
      }
    }
    else if(query==4){
      if(count(bit, mask[m])==masksum(mask[m])){
        cout<<1<<endl;
      }
      else{
        cout<<0<<endl;
      }
    }
    else if(query==5){
      if(count(bit, mask[m])>0){
        cout<<1<<endl;
      }
      else{
        cout<<0<<endl;
      }
    }
    else if(query==6){
      if(count(bit, mask[m])==0){
        cout<<1<<endl;
      }
      else{
        cout<<0<<endl;
      }
    }
    else if(query==7){
      cout<<count(bit,mask[m])<<endl;
    }
    else{
      cout<<decode(bit,mask[m])<<endl;
    }

  }
  return 0;
}

int count(int* bit, int* mask){
  int retval=0;
  for(int i=0;i<64;i++){
    if(mask[i]==1){
      retval+=bit[i];
    }
  }
  return retval;
}

int masksum(int* mask){
  int dummy[64];
  for(int i=0;i<64;i++){
    dummy[i]=1;
  }
  return count(mask, dummy);
}

unsigned long decode(int* bit, int* mask){
  unsigned long retval=0;
  for(int i=0;i<64;i++){
    if(mask[i]==1){
      retval+=((unsigned long)bit[i])*((unsigned long)pow(2,i));
    }
  }
  return retval;
}
