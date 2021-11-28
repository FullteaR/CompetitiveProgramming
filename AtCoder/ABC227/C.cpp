#include <iostream>
#include <cmath>
using namespace std;


int main(void){
    long long N;
    cin>>N;
    long long retval=0;
    const long long N1_3 = pow(N, 1.0/3);
    for(long long A=1;A<=N1_3+1;A++){
        long long NA1_2 = pow(N/A, 0.5);
        for(long long B=A;B<=NA1_2+1;B++){
            long long C_count = N/(A*B) - B + 1;
            if(C_count>0){
                retval+=C_count;
            }
        }
    }
    cout<<retval<<endl;
    return 0;
}