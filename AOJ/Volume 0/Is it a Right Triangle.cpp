#include <iostream>
using namespace std;

int main(void){
        int N;
        int a,b,c;
        cin>>N;
        for(int i=0; i<N; i++) {
                cin>>a>>b>>c;

                if(a*a+b*b==c*c or a*a+c*c==b*b or b*b+c*c==a*a) {
                        cout<<"YES"<<endl;
                }
                else{
                        cout<<"NO"<<endl;
                }
        }
        return 0;

}
