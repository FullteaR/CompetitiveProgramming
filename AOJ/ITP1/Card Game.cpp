#include <iostream>
using namespace std;

int main(void){
        string Taro;
        string Hanako;
        int n;
        cin>>n;
        int taro_score=0;
        int hanako_score=0;
        for(int i=0; i<n; i++) {
                cin>>Taro>>Hanako;
                if(Taro==Hanako) {
                        taro_score+=1;
                        hanako_score+=1;
                }
                else if(Taro<Hanako) {
                        hanako_score+=3;
                }
                else{
                        taro_score+=3;
                }
        }
        cout<<taro_score<<" "<<hanako_score<<endl;
        return 0;
}
