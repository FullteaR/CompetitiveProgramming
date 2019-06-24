#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int* row=(int*)malloc(sizeof(int)*n);
    int u,k;
    int v;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            row[i]=0;
        }
        cin>>u>>k;
        for(int i=0;i<k;i++){
            cin>>v;
            row[v-1]=1;
        }
        for(int i=0;i<n-1;i++){
            cout<<row[i]<<" ";
        }
        cout<<row[n-1]<<endl;
    }
    return 0;
}
