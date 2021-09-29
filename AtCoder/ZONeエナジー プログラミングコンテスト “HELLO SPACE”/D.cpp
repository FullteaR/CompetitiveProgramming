#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void){
    string S;
    cin>>S;
    deque<char> T;
    int S_size = S.size();
    bool forward = true;
    for(int i=0;i<S_size;i++){
        char c = S[i];
        if(c=='R'){
            forward = !forward;
        }
        else{
            if(forward){
                if(T.size()==0 or T[T.size()-1]!=c){
                    T.push_back(c);
                }
                else{
                    T.pop_back();
                }
            }
            else{
                if(T.size()==0 or T[0]!=c){
                    T.push_front(c);
                }
                else{
                    T.pop_front();
                }
            }
        }
    }
    if(!forward){
        reverse(T.begin(),T.end());
    }
    while(true){
        if(T.size()==0){
            break;
        }
        bool complete=true;
        for(int i=0;i<T.size()-1;i++){
            if(T[i]==T[i+1]){
                T.erase(T.begin()+i,T.begin()+i+2);
                complete=false;
                break;
            }
        }
        if(complete){
            break;
        }
    }
    for(char c : T){
        printf("%c",c);
    }
    cout<<endl;
    return 0;
}