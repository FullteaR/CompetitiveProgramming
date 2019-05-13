#include <iostream>
using namespace std;

int main(void){
    string T;
    int n=0;
    int h=0;
    int shuffle;
    while(1){
        shuffle=0;
        cin>>T;
        if(T=="-"){
            return 0;
        }
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>h;
            shuffle+=h;
        }
        shuffle=shuffle%((int)T.length());
        cout<<T.substr(shuffle,(int)T.length()-shuffle)<<T.substr(0,shuffle)<<endl;
    }
}
