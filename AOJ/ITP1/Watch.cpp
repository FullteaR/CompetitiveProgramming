#include <iostream>
using namespace std;
int main(void){
        int second;
        cin>>second;
        int h,m,s;
        h=second/3600;
        m=(second%3600)/60;
        s=second%60;
        cout<<h<<":"<<m<<":"<<s<<endl;
        return 0;
}
