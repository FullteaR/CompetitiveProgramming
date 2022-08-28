#include <iostream>
using namespace std;

int main(void){
    int N,A,B;
    cin>>N>>A>>B;
    for(int i=0;i<N*A;i++){
        for(int j=0;j<N*B;j++){
            int h = i/A;
            int w = j/B;
            if((h+w)%2==0){
                cout<<".";
            }
            else{
                cout<<"#";
            }
        }
        cout<<endl;
    }
    return 0;
}