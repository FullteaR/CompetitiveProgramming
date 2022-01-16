#include <iostream>
using namespace std;

string west2jp(int Y);
int jp2west(int E, int Y);

int main(void){
    int E,Y;
    cin>>E>>Y;
    if(E==0){
        cout<<west2jp(Y)<<endl;
        return 0;
    }
    else{
        cout<<jp2west(E,Y)<<endl;
    }
    return 0;
}

string west2jp(int Y){
    if(Y<1912){
        return "M"+to_string(Y-1867);
    }
    else if(Y<1926){
        return "T"+to_string(Y-1911);
    }
    else if(Y<1989){
        return "S"+to_string(Y-1925);
    }
    else{
        return "H"+to_string(Y-1988);
    }
}

int jp2west(int E, int Y){
    switch(E){
        case 1:
        return Y+1867;
        case 2:
        return Y+1911;
        case 3:
        return Y+1925;
        case 4:
        return Y+1988;
        default:
        return -1;
    }
}