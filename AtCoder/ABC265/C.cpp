#include <iostream>
using namespace std;

int move(long& i, long& j, bool** accessed, char** grid);

int main(void) {
    int H,W;
    cin>>H>>W;
    H+=2;
    W+=2;
    bool** accessed = new bool*[H];
    char** grid = new char*[H];
    for(long h=0;h<H;h++){
        accessed[h] = new bool[W];
        grid[h] = new char[W];
    }
    for(long w=0;w<W;w++){
        accessed[0][w] = false;
        grid[0][w] = 'S';
        accessed[H-1][w] = false;
        grid[H-1][w] = 'S';
    }
    for(long h=1;h<H-1;h++) {
        accessed[h][0] = false;
        accessed[h][W-1] = false;
        grid[h][0] = 'S';
        grid[h][W-1] = 'S';
        for(long w=1;w<W-1;w++){
            accessed[h][w] = false;
            cin>>grid[h][w];
        }
    }

    long i=1;
    long j=1;
    int success = move(i,j,accessed,grid);
    if(success == 0) {
        cout<<i<<" "<<j<<endl;
    }
    else {
        cout<<"-1"<<endl;
    }
}

int move(long& i, long& j, bool** accessed, char** grid) {
    long next_i;
    long next_j;
    if(grid[i][j]=='U') {
        next_i = i-1;
        next_j = j;
    }
    else if(grid[i][j]=='D') {
        next_i = i+1;
        next_j = j;
    }
    else if(grid[i][j] == 'L') {
        next_i = i;
        next_j = j-1;
    }
    else {
        next_i = i;
        next_j = j+1;
    }

    if(accessed[next_i][next_j]) {
        return -1;
    }
    else if(grid[next_i][next_j] == 'S') {
        return 0;
    }
    accessed[i][j] = true;
    i = next_i;
    j = next_j;
    return move(i,j,accessed,grid);
}