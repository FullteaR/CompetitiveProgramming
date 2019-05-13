#include <iostream>
using namespace std;

char grade(int m,int f,int r);

int main(void){
        int m,f,r;
        while(1) {
                cin>>m>>f>>r;
                if(m==-1 and f==-1 and r==-1) {
                        return 0;
                }
                cout<<grade(m,f,r)<<endl;
        }
}


char grade(int m,int f,int r){
    if(m==-1 or f==-1){
        return 'F';
    }
    if(m+f>=80){
        return 'A';
    }
    else if(m+f>=65){
        return 'B';
    }
    else if(m+f>=50){
        return 'C';
    }
    else if(m+f>=30){
        if(r>=50){
            return 'C';
        }
        else{
            return 'D';
        }
    }
    else{
        return 'F';
    }
}
