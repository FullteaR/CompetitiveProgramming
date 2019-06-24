#include <iostream>
#include <stdlib.h>
using namespace std;

int BubbleSort(int* A,int N);

int main(void){
    int N;
    cin>>N;
    int* A = (int*)malloc(N*sizeof(int));
    int count;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    count=BubbleSort(A,N);
    for(int i=0;i<N-1;i++){
        cout<<A[i]<<" ";
    }
    cout<<A[N-1]<<endl;
    cout<<count<<endl;
}

int BubbleSort(int* A,int N){
    int tmp;
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=N-1;j>i;j--){
            if(A[j]<A[j-1]){
                tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                count++;
            }
        }
    }
    return count;
}
