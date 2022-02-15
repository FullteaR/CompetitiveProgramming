#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    int N;
    cin>>N;
    int* A = new int[N];
    int sum = 0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }
    int mean = sum/N;
    for(int i=0;i<N;i++){
        int a = A[i];
        cout<<abs(a-mean)<<endl;
    }
    return 0;
}