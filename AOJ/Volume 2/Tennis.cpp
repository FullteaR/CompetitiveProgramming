#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void game(string S, int A, int B, int j, int y, vector<string> * v);

int main(void){
  int j,y;
  cin>>j>>y;
  vector<string> v;
  game("", 0, 0, j, y, &v);
  sort(v.begin(),v.end());
  for(auto iter=v.begin();iter!=v.end();iter++){
    cout<<*iter<<endl;
  }
  return 0;
}

void game(string S, int A, int B, int j, int y, vector<string>* v){
  if(A==j and B==y){

    v->push_back(S);
  }
  if(A==5 and B<4){
    return ;
  }
  if(A<4 and B==5){
    return ;
  }
  if((A==6 and B==4) or (A==5 and B==5) or (A==4 and B==6)){
    return ;
  }
  else{
    game(S+"A", A+1, B, j, y, v);
    game(S+"B", A, B+1, j, y, v);
  }
  return ;
}
