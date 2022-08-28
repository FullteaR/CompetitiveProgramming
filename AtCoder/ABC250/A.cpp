#include <iostream>
using namespace std;

int main(void){
    int H, W, R, C;
    cin>>H>>W;
    cin>>R>>C;

    int count = 0;
    if(R>1){
        count++;
    }
    if(R<H){
        count++;
    }
    if(C>1){
        count++;
    }
    if(C<W){
        count++;
    }
    cout<<count<<endl;
}