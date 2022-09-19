#include <iostream>
using namespace std;

int main(void) {
    int X,Y,N;
    cin>>X>>Y>>N;
    int price;
    if(3*X>Y) {
        price = (N/3)*Y + (N%3)*X;
    }
    else {
        price = N*X;
    }
    cout<<price<<endl;
    return 0;
}