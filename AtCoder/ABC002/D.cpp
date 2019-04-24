#include <iostream>
using namespace std;


int main(void){
    int friends[12][12]={0};
    int N,M;
    int x,y;

    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>x>>y;
        friends[x-1][y-1]=1;
        friends[y-1][x-1]=1;
    }
    cout<<friends<<endl;

    return 0;
}
