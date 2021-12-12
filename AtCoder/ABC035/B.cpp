#include <iostream>
using namespace std;

int main(void){
    string S;
    cin>>S;
    int T;
    cin>>T;
    int x = 0;
    int y = 0;
    int unknown = 0;
    for(char c:S){
        if(c=='L'){
            x--;
        }
        else if(c=='R'){
            x++;
        }
        else if(c=='U'){
            y++;
        }
        else if(c=='D'){
            y--;
        }
        else{
            unknown++;
        }
    }
    int dist = abs(x)+abs(y);
    if(T==1){
        cout<<dist + unknown<<endl;
    }
    else{
        if(dist%2==unknown%2){
            cout<<max(0, dist-unknown)<<endl;
        }
        else{
            cout<<max(1, dist-unknown)<<endl;
        }
    }
    return 0;
}