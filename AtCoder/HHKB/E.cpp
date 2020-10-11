#include <iostream>
#include <utility>
#include <cassert>
using namespace std;
#define mod 1000000007



int main(void){
  long long* pow2 = new long long[2000+2000+10];
  pow2[0]=1;
  for(long long i=1;i<2000+2000+10;i++){
    pow2[i]=(pow2[i-1]*2)%mod;
  }



  long long H,W;
  cin>>H>>W;
  H+=2;
  W+=2;
  bool **S = new bool*[H];
  for (long long i = 0; i < H; i++) {
    S[i] = new bool[W];
  }
  for(long long w=0;w<W;w++){
    S[0][w]=false;
    S[H-1][w]=false;
  }
  long long K=0;
  for(long long h=1;h<H-1;h++){
    S[h][0]=false;
    S[h][W-1]=false;
    for(long long w=1;w<W-1;w++){
      char tmp;
      cin>>tmp;
      assert(tmp=='.' or tmp=='#');
      S[h][w]=(tmp=='.');
      if(tmp=='.'){
        K++;
      }
    }
  }


  pair<long long,long long> **total = new pair<long long,long long>*[H];
  for (long long i = 0; i < H; i++) {
    total[i] = new pair<long long,long long>[W];
  }
  for(long long h=0;h<H;h++){
    for(long long w=0;w<W;w++){
      total[h][w].first=0;
      total[h][w].second=0;
    }
  }

  for(long long h=0;h<H;h++){
    for(long long w=0;w<W;w++){
      if(S[h][w]==false){
        continue;
      }

      if(S[h][w-1]==false){
        long long yoko=0;
        while(S[h][w+yoko]){
          yoko++;
        }
        total[h][w].first=yoko;
      }
      else{
        total[h][w].first=total[h][w-1].first;
      }

      if(S[h-1][w]==false){
        long long tate=0;
        while(S[h+tate][w]){
          tate++;
        }
        total[h][w].second=tate;
      }
      else{
        total[h][w].second=total[h-1][w].second;
      }
    }
  }

  long long retval=0;
  for(long long h=0;h<H;h++){
    for(long long w=0;w<W;w++){
      if(S[h][w]==false){
        continue;
      }
      long long masu=total[h][w].first+total[h][w].second-1;
      assert(masu>0);
      retval+=pow2[K]-pow2[K-masu];
      retval=retval%mod;
    }
  }
  assert(retval>=0);
  cout<<retval%mod<<endl;
  return 0;
}
