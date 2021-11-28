#include <iostream>
using namespace std;

int main(void){
    bool* avail = new bool[1001];
    for(int i=0;i<=1000;i++){
        avail[i]=false;
    }
    for(int a=1;a<=250;a++){
        for(int b=1;b<=250;b++){
            int S = 4*a*b+3*a+3*b;
            if(S<=1000){
                avail[S]=true;
            }
        }
    }
    int N;
    cin>>N;
    int retval=0;
    for(int i=0;i<N;i++){
        int S;
        cin>>S;
        if(avail[S]==false){
            retval++;
        }
    }
    cout<<retval<<endl;
    return 0;
}