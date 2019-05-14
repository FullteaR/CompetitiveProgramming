#include <iostream>
using namespace std;

int main(void){
        int n;
        int a,b,c,d;
        int count;
        while(cin>>n) {
                count=0;
                for(a=0; a<=9; a++) {
                        for(b=0; b<=9; b++) {
                                for(c=0; c<=9; c++) {
                                        d=n-a-b-c;
                                        if(0<=d and d<=9) {count++;}
                                }
                        }
                }
                cout<<count<<endl;
        }
        return 0;
}
