#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MONEY_MAX 1000010

using namespace std;


int main(void){
  bool* prime=(bool*)malloc(MONEY_MAX*sizeof(bool));

  for(int i=0;i<MONEY_MAX;i++){
    prime[i]=true;
  }

  prime[0]=false;
  prime[1]=false;
  for(int i=2;i<sqrt(MONEY_MAX)+10;i++){
    if(prime[i]==false){continue;}
    int k=2;
    while(k*i<MONEY_MAX){
      prime[k*i]=false;
      k++;
    }
  }

  int n,x;
  while(true){
    cin>>n>>x;
    if(n==0 and x==0){break;}
    int v[n];
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    bool* table[n];
    for(int i=0;i<n;i++){
      table[i]=(bool*)malloc(sizeof(bool)*(x+1));
      for(int j=0;j<=x;j++){
        table[i][j]=false;
      }
    }
    for(int j=0;j<=x;j++){
      table[0][j]=(j%v[0]==0);
    }
    for(int i=1;i<n;i++){
      for(int j=0;j<=x;j++){
        if(j-v[i]>=0){
          table[i][j]=table[i-1][j] or table[i-1][j-v[i]] or table[i][j-v[i]];
        }
        else{
          table[i][j]=table[i-1][j];
        }
      }
    }
    for(int s=x;s>=0;s--){
      if(prime[s] and table[n-1][s]){
        cout<<s<<endl;
        break;
      }
      if(s==0){
        cout<<"NA"<<endl;
      }
    }
    for(int i=0;i<n;i++){
      free(table[i]);
    }
  }

  return 0;
}
