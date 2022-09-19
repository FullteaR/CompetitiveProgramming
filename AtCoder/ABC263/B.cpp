#include <iostream>
#include <unordered_map>
using namespace std;

int main(void) {
    int N;
    cin>>N;
    unordered_map<int,int> parents;
    parents.clear();
    for(int i=2;i<=N;i++) {
        cin>>parents[i];
    }

    int retval=0;
    while(N!=1) {
        retval++;
        N = parents[N];
    }
    cout<<retval<<endl;
    return 0;
}