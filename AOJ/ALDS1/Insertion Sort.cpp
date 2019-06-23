#include <iostream>
#include <stdlib.h>
using namespace std;
int main(void){
    int N;
    cin>>N;
    int* A = (int*)malloc(N*sizeof(int));
    int v,j;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    for(int k=0;k<N;k++){
        if(k<N-1){
            cout<<A[k]<<" ";
        }
        else{
            cout<<A[k]<<endl;
        }
    }

    for(int i=1;i<N;i++){
        v=A[i];
        j=i-1;
        while(j>=0 and A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;

        for(int k=0;k<N;k++){
            if(k<N-1){
                cout<<A[k]<<" ";
            }
            else{
                cout<<A[k]<<endl;
            }
        }
    }
    return 0;
}
