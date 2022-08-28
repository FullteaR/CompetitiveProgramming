#include <iostream>
using namespace std;

int main(void){
    string grid[] = {
        "bbbbbbbbbbbbbbb",
        "bwwwwwwwwwwwwwb",
        "bwbbbbbbbbbbbwb",
        "bwbwwwwwwwwwbwb",
        "bwbwbbbbbbbwbwb",
        "bwbwbwwwwwbwbwb",
        "bwbwbwbbbwbwbwb",
        "bwbwbwbwbwbwbwb",
        "bwbwbwbbbwbwbwb",
        "bwbwbwwwwwbwbwb",
        "bwbwbbbbbbbwbwb",
        "bwbwwwwwwwwwbwb",
        "bwbbbbbbbbbbbwb",
        "bwwwwwwwwwwwwwb",
        "bbbbbbbbbbbbbbb"
    };
    int R,C;
    cin>>R>>C;
    R--;
    C--;
    if(grid[R][C]=='b'){
        cout<<"black"<<endl;
    }
    else{
        cout<<"white"<<endl;
    }
    return 0;   
}