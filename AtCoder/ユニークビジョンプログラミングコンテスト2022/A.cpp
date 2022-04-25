#include <iostream>
using namespace std;

int main(void){
    bool* used = new bool[10];
    for(int i=0;i<10;i++){
        used[i] = false;
    }
    string S;
    cin>>S;
    for(char c:S){
        used[c-'0'] = true;
    }
    for(int i=0;i<10;i++){
        if(used[i]==false){
            cout<<i<<endl;
        }
    }
    return 0;
}