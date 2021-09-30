#include <iostream>
using namespace std;
#define INF 1000010

void swap(int i, int j, int* p){
    int tmp;
    tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;
}

void copy(int* array1, int* array2, int N){
    for(int i=0;i<N;i++){
        array2[i] = array1[i];
    }
}

bool equal(int* array1, int* array2, int N){
    for(int i=0;i<N;i++){
        if(array1[i]!=array2[i]){
            return false;
        }
    }
    return true;
}

void op1(int* puzzle){
    swap(7,22,puzzle);
    swap(8,23,puzzle);
    swap(9,24,puzzle);
    swap(13,18,puzzle);
    swap(10,12,puzzle);
}

void op2(int* puzzle){
    swap(1,28,puzzle);
    swap(2,29,puzzle);
    swap(3,30,puzzle);
    swap(15,16,puzzle);
    swap(19,21,puzzle);
}

void op3(int* puzzle){
    swap(1,24,puzzle);
    swap(4,27,puzzle);
    swap(7,30,puzzle);
    swap(10,21,puzzle);
    swap(16,18,puzzle);
}

void op4(int* puzzle){
    swap(3,22,puzzle);
    swap(6,25,puzzle);
    swap(9,28,puzzle);
    swap(12,19,puzzle);
    swap(13,15,puzzle);
}

int solve(int *puzzle, int depth, int N, int op){
    if(depth>8){
        return INF;
    }
    int goal[] = {0,1,1,1,1,1,1,1,1,1,2,2,2,4,4,4,6,6,6,5,5,5,3,3,3,3,3,3,3,3,3};
    if(equal(goal, puzzle, N)){
        return 0;
    }
    int retval = INF+100;
    int* puzzle_ = new int[N];
    if(op!=1){
        copy(puzzle, puzzle_,N);
        op1(puzzle_);
        retval = min(retval, 1+solve(puzzle_, depth+1, N, 1));
    }

    if(op!=2){
        copy(puzzle, puzzle_,N);
        op2(puzzle_);
        retval = min(retval, 1+solve(puzzle_, depth+1, N, 2));
    }

    if(op!=3){
        copy(puzzle, puzzle_,N);
        op3(puzzle_);
        retval = min(retval, 1+solve(puzzle_, depth+1, N, 3));
    }

    if(op!=4){
        copy(puzzle, puzzle_,N);
        op4(puzzle_);
        retval = min(retval, 1+solve(puzzle_, depth+1, N, 4));
    }



    return retval;
}


int main(void){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int* puzzle = new int[31];
        puzzle[0]=0;
        for(int j=1;j<=30;j++){
            cin>>puzzle[j];
        }
        cout<<solve(puzzle,0,31,-1)<<endl;
    }
    return 0;
}