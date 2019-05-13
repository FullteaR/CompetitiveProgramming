#include <iostream>
using namespace std;

int main(void){
        string s;
        string p;
        cin>>s;
        cin>>p;
        s+=s;
        if((int)s.rfind(p)==-1) {
                cout<<"No"<<endl;
        }
        else{
                cout<<"Yes"<<endl;
        }
        return 0;
}
