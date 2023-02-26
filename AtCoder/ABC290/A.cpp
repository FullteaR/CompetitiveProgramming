#include <iostream>
using namespace std;

int main(void){
    int N,M;
    cin>>N>>M;
    int* A = new int[N];
    long total = 0;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<M;i++){
        int B;
        cin>>B;
        total += A[B-1];
    }
    cout<<total<<endl;
    return 0;
}