#include <iostream>
using namespace std;

int main(void){
        int c=-1;
        int i=1;
        for(;;) {
                cin>>c;
                if(c==0) {
                        return 0;
                }
                cout<<"Case "<<i<<": "<<c<<endl;
                i++;
        }
}
