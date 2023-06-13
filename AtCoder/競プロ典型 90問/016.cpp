#include <iostream>
using namespace std;

int main(void) {
    long N;
    cin>>N;
    long A,B,C;
    cin>>A>>B>>C;
    long retval = 100000;
    for(int a=0;a<=9999;a++) {
        for(long b=0;b<=9999;b++) {
            long rest = N-a*A-b*B;
            if(rest<0){
                continue;
            }
            if(rest%C==0){
                long c = rest/C;
                retval = min(a+b+c, retval);
            }
        }
    }
    cout<<retval<<endl;
}