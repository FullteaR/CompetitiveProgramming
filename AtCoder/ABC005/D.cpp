#include <iostream>
using namespace std;

int main(void){
  int N;
  cin>>N;
  int D[N][N];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>D[i][j];
    }
  }
  int Q;
  cin>>Q;
  int* P = new int[Q];
  for(int i=0;i<Q;i++){
    cin>>P[i];
  }

  long* delicious = new long[N*N+10];
  for(int i=0;i<N*N+10;i++){
    delicious[i]=0;
  }
  for(int l=0;l<N;l++){
    for(int u=0;u<N;u++){
      for(int r=l;r<N;r++){
        for(int d=u;d<N;d++){
          int area=abs((r-l+1)*(d-u+1));
          long _delicious=0;
          for(int i=l;i<=r;i++){
            for(int j=u;j<=d;j++){
              _delicious+=D[j][i];
            }
          }
          delicious[area]=max(delicious[area],_delicious);
        }
      }
    }
  }
  for(int i=0;i<Q;i++){
    long retval=0;
    for(int j=0;j<=P[i];j++){
      retval=max(retval, delicious[j]);
    }
    cout<<retval<<endl;
  }
  return 0;
}
