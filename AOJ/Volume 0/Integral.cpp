#include <iostream>
using namespace std;

int main(void){
        int d;
        int s;
        while(cin>>d) {
                s=0;
                for(int i=0; i<600; i+=d) {
                        s+=d*i*i;
                }
                cout<<s<<endl;
        }
        return 0;
}
