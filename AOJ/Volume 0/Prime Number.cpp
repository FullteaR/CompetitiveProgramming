#include <iostream>
using namespace std;
#define tablesize 1000010
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
    int retval;
    while(cin>>n){
        retval=0;
        for(int i=0;i<=n;i++){
            retval+=table[i];
        }
        cout<<retval<<endl;
    }
    return 0;
}
