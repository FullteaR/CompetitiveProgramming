#include <iostream>
#include <set>
#define NUM_PEOPLE 5
using namespace std;


bool aiko(int* h);
int win(int* h);

int main(void){
  int h[NUM_PEOPLE];
  int retval[NUM_PEOPLE];
  while(true){
    for(int i=0;i<NUM_PEOPLE;i++){
      cin>>h[i];
      if(h[i]==0){return 0;}
    }
    if(aiko(h)){
      for(int i=0;i<NUM_PEOPLE;i++){
        retval[i]=3;
      }
    }
    else{
      int w=win(h);
      for(int i=0;i<NUM_PEOPLE;i++){
        if(h[i]==w){
          retval[i]=1;
        }
        else{
          retval[i]=2;
        }
      }
    }
    for(int i=0;i<NUM_PEOPLE;i++){
      cout<<retval[i]<<endl;
    }
  }
}

bool aiko(int* h){
  set<int> st(h,h+NUM_PEOPLE);
  int count=0;
  for(auto iter=st.begin();iter!=st.end();iter++){
    count++;
  }
  return count==3 or count==1;
}

int win(int* h){
  set<int> st(h,h+NUM_PEOPLE);
  auto iter=st.begin();
  int h1=*iter;
  iter++;
  int h2=*iter;
  if((h1==1 and h2==2) or (h1==2 and h2==1)){
    return 1;
  }
  else if((h1==3 and h2==2) or (h1==2 and h2==3)){
    return 2;
  }
  else{
    return 3;
  }
}
