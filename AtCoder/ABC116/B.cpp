#include <iostream>
#include <unordered_set>
using namespace std;

int f(int n);

int main(void){
    int s;
    cin>>s;
    int i = 1;
    unordered_set<int> d;
    d.clear();
    while(d.find(s) == d.end()){
        d.insert(s);
        i++;
        s = f(s);
    }
    cout<<i<<endl;
}

int f(int n){
    if(n%2==0){
        return n/2;
    }
    else{
        return 3*n+1;
    }
}