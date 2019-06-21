#include <iostream>
#include <vector>
using namespace std;


int main(void){
    int n;
    int ball;
    int B_last, C_last;
    bool flag;
    cin>>n;
    vector<int> B(1,0);
    vector<int> C(1,0);
    for(int i=0;i<n;i++){
        flag=true;

        for(int j=0;j<10;j++){
            cin>>ball;
            B_last=B[B.size()-1];
            C_last=C[C.size()-1];
            if(B_last>=C_last){
                if(ball>B_last){
                    B.push_back(ball);
                }
                else if(ball>C_last){
                    C.push_back(ball);
                }
                else{
                    flag=false;
                }
            }
            else{
                if(ball>C_last){
                    C.push_back(ball);
                }
                else if(ball>B_last){
                    B.push_back(ball);
                }
                else{
                    flag=false;
                }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        B.clear();
        C.clear();
        B.push_back(0);
        C.push_back(0);
    }
    return 0;
}
