#include <iostream>
#include <cassert>
using namespace std;

bool check3(long A, long B, long C, long X, long Y);
bool _check3(long A, long B, long C, long X, long Y);
bool check2(long A, long B, long X, long Y);
bool check1(long A, long X, long Y);

int main(void){
    long X,Y;
    long A,B,C;
    cin>>X>>Y>>A>>B>>C;
    if(check3(A,B,C,X,Y)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}

bool check1(long A, long X, long Y){
    if(X<=0 or Y<=0){
        return false;
    }
    return A<=X*Y;
}

bool check2(long A, long B, long X, long Y){
    if(X<=0 or Y<=0){
        return false;
    }
    long tate = Y;
    long yoko;
    if(B%Y==0){
        yoko = B/Y;
    }
    else{
        yoko = B/Y+1;
    }
    assert(tate*yoko>=B);
    if(check1(A, X-yoko, Y)){
        return true;
    }

    yoko = X;
    if(B%X==0){
        tate = B/X;
    }
    else{
        tate = B/X+1;
    }
    assert(tate*yoko>=B);
    return check1(A,X,Y-tate);
}

bool check3(long A, long B, long C, long X, long Y){
    return _check3(A,B,C,X,Y) or _check3(A,C,B,X,Y) or _check3(B,C,A,X,Y);
}

bool _check3(long A, long B, long C, long X, long Y){
    long tate = Y;
    long yoko;
    if(C%Y==0){
        yoko = C/Y;
    }
    else{
        yoko = C/Y+1;
    }
    assert(tate*yoko>=C);
    if(check2(A,B, X-yoko, Y)){
        return true;
    }

    yoko = X;
    if(C%X==0){
        tate = C/X;
    }
    else{
        tate = C/X+1;
    }
    assert(tate*yoko>=C);
    return check2(A,B,X,Y-tate);
}