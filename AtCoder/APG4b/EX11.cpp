#include <iostream>
using namespace std;

int main(void){
    int N;
    int A;
    cin>>N;
    cin>>A;
    for(int i=0;i<N;i++){
        string op;
        int B;
        cin>>op>>B;
        if(op=="+"){
            A+=B;
        }
        else if(op=="-"){
            A-=B;
        }
        else if(op=="*"){
            A*=B;
        }
        else if(op=="/"){
            if(B==0){
                cout<<"error"<<endl;
                return 0;
            }
            A/=B;
        }
        cout<<i+1<<":"<<A<<endl;
    }
    return 0;
}