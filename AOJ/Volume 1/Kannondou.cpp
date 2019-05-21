#include <iostream>
using namespace std;

long long kannondou(int n);

int main(void){
        int n;
        while(1) {
                cin>>n;
                if(n==0) return 0;
                cout<<kannondou(n)/3650 +1<<endl;
        }
}

long long kannondou(int n){
        //通るんかい...。
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        else return (kannondou(n-1)+kannondou(n-2)+kannondou(n-3));
}
