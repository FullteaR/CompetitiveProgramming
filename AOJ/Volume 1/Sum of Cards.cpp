#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(void){
  int m;
  while(1){
    cin>>m;
    if(m==0)break;
    map<int,int> card;
    vector<int> A;
    int a,b;
    for(int i=0;i<m;i++){
      cin>>a>>b;
      A.push_back(a);
      card[a]=b;
    }
    for(int i=m;i<7;i++){
      A.push_back(0);
      card[0]=0;
    }
    int max=0;
    for(int i=0;i<m;i++){
      max+=A[i]*card[A[i]];
    }
    map<int,int> pattern;
    for(int i=0;i<max+1;i++){
      pattern[i]=0;
    }
    int cost;
    for(int i0=0;i0<=card[A[0]];i0++){
      for(int i1=0;i1<=card[A[1]];i1++){
        for(int i2=0;i2<=card[A[2]];i2++){
          for(int i3=0;i3<=card[A[3]];i3++){
            for(int i4=0;i4<=card[A[4]];i4++){
              for(int i5=0;i5<=card[A[5]];i5++){
                for(int i6=0;i6<=card[A[6]];i6++){
                  cost=i0*A[0]+i1*A[1]+i2*A[2]+i3*A[3]+i4*A[4]+i5*A[5]+i6*A[6];
                  pattern[cost]=pattern[cost]+1;
                }
              }
            }
          }
        }
      }
    }
    int g;
    cin>>g;
    int n;
    for(int i=0;i<g;i++){
      cin>>n;
      cout<<pattern[n]<<endl;
    }
  }
  return 0;

}
