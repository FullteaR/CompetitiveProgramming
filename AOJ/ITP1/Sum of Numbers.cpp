#include <iostream>
#include <string.h>
using namespace std;

int s(char* n){
        int retval=0;
        int i=0;
        while(n[i]!='\0') {
                retval+=n[i]-'0';
                i++;
        }
        return retval;
}

int main(void){
        char n[100000];
        while(1) {
                cin>>n;
                if(strcmp(n,"0")==0) {
                        return 0;
                }
                cout<<s(n)<<endl;
        }
        return 0;
}
