#include <iostream>
using namespace std;

int main(void){
    int N;
    char S[100010];
    cin>>N;
    cin>>S;
    int count=0;
    for(int i=0;i<N-1;i++){
        if(S[i]!=S[i+1]){
            count++;
            i++;
        }
    }
    cout<<count<<endl;
    return 0;

}
