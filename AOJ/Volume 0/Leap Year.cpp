#include <iostream>
#include <vector>
using namespace std;

void leap(int a, int b);
bool check(int a);

int main(void){
  int a,b;
  bool begin=true;
  while(1){
    cin>>a>>b;
    if(a==0 && b==0)break;
    if(begin==false)cout<<endl;
    leap(a,b);
    begin=false;
  }
}

void leap(int a, int b){
  vector<int> year;
  for(int i=a;i<=b;i++){
    if(check(i)){
      year.push_back(i);
    }
  }
  if(year.size()==0){
    cout<<"NA"<<endl;
  }
  else{
    for(int i=0;i<year.size();i++){
      cout<<year[i]<<endl;
    }
  }
}

bool check(int a){
  if(a%400==0){return true;}
  else if(a%100==0){return false;}
  else if(a%4==0){return true;}
  else{return false;}
}
