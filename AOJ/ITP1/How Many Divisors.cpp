#include <iostream>
using namespace std;

int main(void){
        int a,b,c;
        int retval;
        cin>>a>>b>>c;
        for(int i=a; i<=b; i++) {//実行時間に収まるなら何でもいいって誰かが言っていた
                if(c%i==0) {
                        retval+=1;
                }
        }
        cout<<retval<<endl;
        return 0;
}
