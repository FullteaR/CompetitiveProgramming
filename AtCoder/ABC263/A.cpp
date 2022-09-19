#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    int* cards = new int[5];
    for(int i=0;i<5;i++) {
        cin>>cards[i];
    }
    sort(cards, cards+5);
    if(cards[0]==cards[1] && cards[1]==cards[2] && cards[2]!=cards[3] && cards[3]==cards[4]) {
        cout<<"Yes"<<endl;
    }
    else if(cards[0]==cards[1] && cards[1]!=cards[2] && cards[2]==cards[3] && cards[3]==cards[4]) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    return 0;
}