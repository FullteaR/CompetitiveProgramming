#include <iostream>
using namespace std;

int main(void){
  string board1,board2,board3;
  while(cin>>board1>>board2>>board3){
    if(board1[0]!='+' and board1[0]==board1[1] and board1[1]==board1[2]){
      cout<<board1[0]<<endl;
      continue;
    }
    if(board2[0]!='+' and board2[0]==board2[1] and board2[1]==board2[2]){
      cout<<board2[0]<<endl;
      continue;
    }
    if(board3[0]!='+' and board3[0]==board3[1] and board3[1]==board3[2]){
      cout<<board3[0]<<endl;
      continue;
    }
    if(board1[0]!='+' and board1[0]==board2[0] and board2[0]==board3[0]){
      cout<<board1[0]<<endl;
      continue;
    }
    if(board1[1]!='+' and board1[1]==board2[1] and board2[1]==board3[1]){
      cout<<board1[1]<<endl;
      continue;
    }
    if(board1[2]!='+' and board1[2]==board2[2] and board2[2]==board3[2]){
      cout<<board1[2]<<endl;
      continue;
    }
    if(board1[0]!='+' and board1[0]==board2[1] and board2[1]==board3[2]){
      cout<<board1[0]<<endl;
      continue;
    }
    if(board1[2]!='+' and board1[2]==board2[1] and board2[1]==board3[0]){
      cout<<board1[2]<<endl;
      continue;
    }
    cout<<"NA"<<endl;
  }
  return 0;
}
