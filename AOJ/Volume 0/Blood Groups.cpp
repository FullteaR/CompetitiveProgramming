#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

int main(void){
  int n;
  char s[100];
  map<string,int> blood;
  blood["A"]=0;
  blood["B"]=0;
  blood["O"]=0;
  blood["AB"]=0;
  while(scanf("%d,%s",&n,s)!=EOF){
    blood[s]+=1;
  }
  cout<<blood["A"]<<endl;
  cout<<blood["B"]<<endl;
  cout<<blood["AB"]<<endl;
  cout<<blood["O"]<<endl;
  return 0;
}
