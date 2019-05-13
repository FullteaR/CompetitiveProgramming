#include <iostream>
using namespace std;

int suit2num(char suit){
        switch(suit) {
        case 'S':
                return 0;
        case 'H':
                return 1;
        case 'C':
                return 2;
        case 'D':
                return 3;
        }
        return -1;
}

char num2suit(int i){
        switch(i) {
        case 0:
                return 'S';
        case 1:
                return 'H';
        case 2:
                return 'C';
        case 3:
                return 'D';
        }
        return ' ';
}

int main(void){
        int n;
        int card[4][13]={0};
        int number;
        char suit;
        cin>>n;
        for(int i=0; i<n; i++) {
                cin>>suit>>number;
                card[suit2num(suit)][number-1]=1;
        }
        for(int i=0; i<4; i++) {
                for(int j=0; j<13; j++) {
                        if(card[i][j]==0) {
                                cout<<num2suit(i)<<" "<<j+1<<endl;
                        }
                }
        }
        return 0;

}
