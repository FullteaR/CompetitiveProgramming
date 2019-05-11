#include <iostream>
using namespace std;

int main(void){
        int x,y;
        while(1) {
                cin>>x>>y;
                if(x==0 and y==0) {
                        return 0;
                }
                cout<<min(x,y)<<" "<<max(x,y)<<endl;
        }
}
