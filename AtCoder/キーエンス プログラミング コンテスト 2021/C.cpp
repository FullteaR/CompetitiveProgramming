#include <iostream>
#include <cassert>
using namespace std;
#define mod 998244353
#define inv_3 332748118

long long pow(long long a, long long b, long long MOD);

int main(void){
  assert((inv_3*3)%mod==1);

  long long H,W,K;
  cin>>H>>W>>K;
  H+=2;
  W+=2;
  long long** roots = new long long* [H];
  char** grid = new char* [H];
  for(long long h=0;h<H;h++){
    roots[h]=new long long[W];
    grid[h]=new char[W];
    for(long long w=0;w<W;w++){
      roots[h][w]=0;
      grid[h][w]='B';
    }
  }
  for(long long w=0;w<W;w++){
    grid[0][w]='N';
    grid[H-1][w]='N';
  }
  for(long long h=0;h<H;h++){
    grid[h][0]='N';
    grid[h][W-1]='N';
  }

  roots[1][1]=pow(3,(H-2)*(W-2)-K,mod);
  for(long long i=0;i<K;i++){
    long long h,w;
    char c;
    cin>>h>>w>>c;
    grid[h][w]=c;
  }

  for(long long h=1;h<H-1;h++){
    for(long long w=1;w<W-1;w++){
      if(grid[h-1][w]=='D' or grid[h-1][w]=='X'){
        roots[h][w]+=roots[h-1][w];
      }
      else if(grid[h-1][w]=='B'){
        roots[h][w]+=roots[h-1][w]*inv_3*2;
      }
      if(grid[h][w-1]=='R' or grid[h][w-1]=='X'){
        roots[h][w]+=roots[h][w-1];
      }
      else if(grid[h][w-1]=='B'){
        roots[h][w]+=roots[h][w-1]*inv_3*2;
      }
      roots[h][w] = roots[h][w]%mod;
    }
  }


  cout<<roots[H-2][W-2]<<endl;
  return 0;
}

long long pow(long long a, long long b, long long MOD){
  if(b==0){
    return 1;
  }
  if(b%2==0){
    long long tmp=pow(a,b/2,MOD);
    return (tmp*tmp)%MOD;
  }
  return (pow(a,b-1,MOD)*a)%MOD;
}
