#include <iostream>
using namespace std;

int main(void){
    string S;
    cin>>S;
    int plus=0;
    int minus=0;
    for(char c : S){
        if(c=='+'){
            plus++;
        }
        else if(c=='-'){
            minus++;
        }
    }
    cout<<1+plus-minus<<endl;
    return 0;
}