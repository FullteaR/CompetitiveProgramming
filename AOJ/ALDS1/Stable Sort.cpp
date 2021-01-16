#include <iostream>
using namespace std;

struct Card{
  int num;
  char suit;
}typedef Card;

int main(void){
  int N;
  cin>>N;
  Card* card_b = new Card[N];
  Card* card_s = new Card[N];

  for(int i=0;i<N;i++){
    char suit;
    int num;
    cin>>suit>>num;
    card_b[i].suit=suit;
    card_s[i].suit=suit;
    card_b[i].num=num;
    card_s[i].num=num;
  }

  for(int i=0;i<N;i++){
    for(int j=N-1;j>i;j--){
      if(card_b[j].num<card_b[j-1].num){
        char suit=card_b[j].suit;
        int num = card_b[j].num;
        card_b[j].suit=card_b[j-1].suit;
        card_b[j].num=card_b[j-1].num;
        card_b[j-1].suit=suit;
        card_b[j-1].num=num;
      }
    }
  }

  for(int i=0;i<N;i++){
    int minj=i;
    for(int j=i;j<N;j++){
      if(card_s[j].num<card_s[minj].num){
        minj=j;
      }
    }
    char suit=card_s[i].suit;
    int num = card_s[i].num;
    card_s[i].suit=card_s[minj].suit;
    card_s[i].num=card_s[minj].num;
    card_s[minj].suit=suit;
    card_s[minj].num=num;

  }

  for(int i=0;i<N;i++){
    cout<<card_b[i].suit<<card_b[i].num;
    if(i==N-1){
      cout<<endl;
    }
    else{
      cout<<" ";
    }
  }
  cout<<"Stable"<<endl;

  for(int i=0;i<N;i++){
    cout<<card_s[i].suit<<card_s[i].num;
    if(i==N-1){
      cout<<endl;
    }
    else{
      cout<<" ";
    }
  }

  for(int i=0;i<N;i++){
    if(card_s[i].num!=card_b[i].num or card_s[i].suit!=card_b[i].suit){
      cout<<"Not stable"<<endl;
      return 0;
    }
  }
  cout<<"Stable"<<endl;
  return 0;

}
