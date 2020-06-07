#include <iostream>
#include <cassert>
using namespace std;
#define INF 100000010

void solve(int N, int* purse,int* retval);
int pay(int N, int* purse, int* retval);
int change(int N, int* retval);


int main(void){
  int N;
  bool start=true;
  while(1){
    cin>>N;
    if(N==0){
      break;
    }
    if(start==false){
      cout<<endl;
    }
    int retval[4];
    int purse[4];
    for(int i=0;i<4;i++){
      cin>>purse[i];
      retval[i]=0;
    }
    solve(N,purse,retval);
    if(retval[0]!=0){
      cout<<"10 "<<retval[0]<<endl;
    }
    if(retval[1]!=0){
      cout<<"50 "<<retval[1]<<endl;
    }
    if(retval[2]!=0){
      cout<<"100 "<<retval[2]<<endl;
    }
    if(retval[3]!=0){
      cout<<"500 "<<retval[3]<<endl;
    }
    start=false;
  }
}

void solve(int N, int* purse,int* retval){
  int _retval=INF;
  for(int cache=0;cache<=20*(10+50+100+500);cache+=10){
    bool dup=false;
    int changes[4];
    int pays[4];
    int pay_amount=pay(N+cache,purse,pays);
    int change_amount=change(cache,changes);
    for(int i=0;i<4;i++){
      if(pays[i]==changes[i] and pays[i]!=0){
        dup=true;
      }
    }
    if(dup==false and _retval>purse[0]+purse[1]+purse[2]+purse[3]-pay_amount+change_amount){
      for(int i=0;i<4;i++){
        retval[i]=pays[i];
      }
      _retval=purse[0]+purse[1]+purse[2]+purse[3]-pay_amount+change_amount;
    }
  }
}

int pay(int N, int* purse, int* retval){
  for(int i=0;i<4;i++){
    retval[i]=0;
  }

  if(N<=purse[0]*10){
    retval[0]=N/10;
    return retval[0]+retval[1]+retval[2]+retval[3];
  }

  N-=purse[0]*10;
  retval[0]=purse[0];
  while(N%50!=0){
    N+=10;
    retval[0]-=1;
    if(retval[0]<0){
      return -1*INF;
    }
  }
  assert(N%50==0);

  if(N<=purse[1]*50){
    retval[1]=N/50;
    return retval[0]+retval[1]+retval[2]+retval[3];
  }

  N-=purse[1]*50;
  retval[1]=purse[1];
  while(N%100!=0){
    N+=50;
    retval[1]-=1;
    if(retval[1]<0){
      return -1*INF;
    }
  }
  assert(N%100==0);

  if(N<=purse[2]*100){
    retval[2]=N/100;
    return retval[0]+retval[1]+retval[2]+retval[3];
  }

  N-=purse[2]*100;
  retval[2]=purse[2];
  while(N%500!=0){
    N+=100;
    retval[2]-=1;
    if(retval[2]<0){
      return -1*INF;
    }
  }
  assert(N%500==0);

  if(N<=purse[3]*500){
    retval[3]=N/500;
    return retval[0]+retval[1]+retval[2]+retval[3];
  }
  else{
    return -1*INF;
  }
}

int change(int N,int* retval){
  retval[3]=N/500;
  N=N%500;
  retval[2]=N/100;
  N=N%100;
  retval[1]=N/50;
  N=N%50;
  retval[0]=N/10;
  N=N%10;// must be zero.
  return retval[0]+retval[1]+retval[2]+retval[3];
}
