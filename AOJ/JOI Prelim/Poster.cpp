#include <iostream>
using namespace std;

void rot90(char** S, int N);
int diff(char** S, char** T, int N);

int main(void){
  int N;
  cin>>N;
  char** S = new char*[N];
  for(int i=0;i<N;i++){
    S[i] = new char[N];
    for(int j=0;j<N;j++){
      cin>>S[i][j];
    }
  }

  char** T = new char*[N];
  for(int i=0;i<N;i++){
    T[i] = new char[N];
    for(int j=0;j<N;j++){
      cin>>T[i][j];
    }
  }
  int retval = diff(S,T,N);
  rot90(S,N);
  retval = min(diff(S,T,N)+1, retval);
  rot90(S,N);
  retval = min(diff(S,T,N)+2, retval);
  rot90(S,N);
  retval = min(diff(S,T,N)+1, retval);
  cout<<retval<<endl;
  return 0;
}


void rot90(char** S, int N){
  char** T = new char*[N];
  for(int i=0;i<N;i++){
    T[i] = new char[N];
    for(int j=0;j<N;j++){
      T[i][j]=S[j][N-i-1];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      S[i][j]=T[i][j];
    }
  }
}
int diff(char** S, char** T,int N){
  int retval=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(S[i][j]!=T[i][j]){
        retval++;
      }
    }
  }
  return retval;
}
