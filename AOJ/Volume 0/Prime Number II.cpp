#include <iostream>
using namespace std;
#define tablesize 60010
#include <math.h>

int main(void){
    int table[tablesize];
    for(int i=0;i<tablesize;i++){
        table[i]=1;
    }
    int k;
    table[0]=0;
    table[1]=0;
    for(int i=2;i<(int)sqrt(tablesize)+10;i++){
        if(table[i]==1){
            k=2;
            while(k*i<=tablesize){
                table[k*i]=0;
                k++;
            }
        }
    }

    int n;
    int small, big;
    while(cin>>n){
      for(int i=n-1;i>0;i--){
        if(table[i]==1){
          small=i;
          break;
        }
      }
      for(int i=n+1;i<tablesize;i++){
        if(table[i]==1){
          big=i;
          break;
        }
      }
      cout<<small<<" "<<big<<endl;
    }
    return 0;
}
