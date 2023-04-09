#include <iostream>
#include <set>
using namespace std;

void search(long used_left, long used_right, long N, set<string>* retval);

int main(void) {
    int N;
    cin>>N;
    if(N%2==1){
        return 0;
    }
    set<string> retval;
    search(0,0,N,&retval);
    for(string r : retval){
        cout<<r<<endl;
    }
}

void search(long used_left, long used_right, long N, set<string>* retval){
    retval->clear();
    if(used_left<used_right) {
        return;
    }
    if(used_left==N/2 and used_right==N/2){
        retval->insert("");
        return;
    }
    if(used_left>N/2 or used_right>N/2){
        return;
    }

    set<string> retval_left;
    search(used_left+1, used_right, N, &retval_left);
    for(string r : retval_left){
        retval->insert("("+r);
    }
    set<string> retval_right;
    search(used_left, used_right+1, N, &retval_right);
    for(string r : retval_right){
        retval->insert(")"+r);
    }
}