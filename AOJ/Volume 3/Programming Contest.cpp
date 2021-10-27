#include <iostream>
using namespace std;

int count(int* p, int K, int N);

int main(void){
    int N;
    cin>>N;
    int* p = new int[N];
    for(int i=0;i<N;i++){
        cin>>p[i];
    }
    for(int s=100;s>=0;s--){
        if(s<=count(p, s, N)){
            cout<<s<<endl;
            return 0;
        }
    }
}

int count(int* p, int K, int N){
    int retval=0;
    for(int i=0;i<N;i++){
        if(p[i]>=K){
            retval++;
        }
    }
    return retval;
}