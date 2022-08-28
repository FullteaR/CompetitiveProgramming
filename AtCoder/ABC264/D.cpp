#include <iostream>
using namespace std;

int findInd(string S, char c){
    for(int i=0;i<S.size();i++){
        if(S[i] == c){
            return i;
        }
    }
    return -1;
}

int main(void){
    string S;
    cin>>S;
    string atcoder = "atcoder";
    int retval = 0;
    for(int i=0;i<atcoder.size();i++){
        int ind = findInd(S, atcoder[i]);
        retval += ind;
        S = S.replace(ind, 1, "");
    }
    cout<<retval<<endl;
}