#include <iostream>
using namespace std;

int main(void){
        char W[40];
        cin>>W;
        int i=0;
        while(W[i]) {
                if (W[i]=='a' || W[i]=='i' || W[i]=='u' || W[i] == 'e' || W[i] == 'o') {

                }
                else{
                        cout<<W[i];
                }
                i++;
        }
        cout<<endl;
        return 0;
}
