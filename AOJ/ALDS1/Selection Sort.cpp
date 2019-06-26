#include <iostream>
#include <stdlib.h>
using namespace std;

int sort(int* A, int N);

int main(void){
    int N;
    cin>>N;
    int* A = (int*)malloc(sizeof(int)*N);
    int count;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    count=sort(A,N);
    for(int i=0;i<N-1;i++){
        cout<<A[i]<<" ";
    }
    cout<<A[N-1]<<endl;
    cout<<count<<endl;
    return 0;
}

int sort(int* A, int N){
    int mini;
    int tmp;
    int count=0;
    for(int i=0;i<N;i++){
        mini=i;
        for(int j=i;j<N;j++){
            if(A[j]<A[mini]){
                mini=j;
            }
        }
        tmp=A[i];
        A[i]=A[mini];
        A[mini]=tmp;
        if(mini!=i){
            count++;
        }
    }
    return count;
}
