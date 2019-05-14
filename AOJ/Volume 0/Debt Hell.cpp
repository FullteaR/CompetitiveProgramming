#include <iostream>
using namespace std;

int main(void){
        int n;
        cin>>n;
        long debt=100000;
        for(int i=0; i<n; i++) {
                debt=(((long)(debt*1.05)+999)/1000)*1000;
        }
        cout<<debt<<endl;
        return 0;
}
