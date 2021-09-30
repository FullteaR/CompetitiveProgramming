#include <iostream>
using namespace std;

int main(void){
    string retval = "";
    long long w;
    cin>>w;
    long long weight = 1;

    while(w!=0){
        switch(w%(weight*3)){
            case 1:
                retval = '+'+retval;
                w--;
                break;
            case 2:
                retval = '-'+retval;
                w++;
                break;
            case 0:
                retval = '0'+retval;
                break;
        }
        w = w/3;
    }
    cout<<retval<<endl;

    return 0;
}