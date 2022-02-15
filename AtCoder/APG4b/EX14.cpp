#include <iostream>
using namespace std;

int main(void){
    int A,B,C;
    cin>>A>>B>>C;
    cout<<max(max(A,B),C)-min(min(A,B),C)<<endl;
    return 0;
}