#include <vector>
#include <iostream>

using namespace std;

bool check(vector<int> *v);
void ope(vector<int> *v);

int main(void){
  while(1){
    int N;
    cin>>N;
    if(N==0){return 0;}
    vector<int> v;
    v.clear();
    for(int i=0;i<N;i++){
      int b;
      cin>>b;
      v.push_back(b);
    }
    int retval=10010;
    for(int i=0;i<10000;i++){
      if(check(&v)){
        retval=min(i,retval);
      }
      ope(&v);
    }
    if(retval==10010){
      cout<<"-1"<<endl;
    }
    else{
      cout<<retval<<endl;
    }
  }
}

bool check(vector<int> *v){
  int i=1;
  for(int j=0;j<v->size();j++){
    if((*v)[j]==0) continue;
    if(i!=(*v)[j]) return false;
    i++;
  }
  return true;
}

void ope(vector<int> *v){
  int stack=0;
  for(int i=0;i<v->size();i++){
    if((*v)[i]>0){
      (*v)[i]-=1;
      stack++;
    }
  }
  v->push_back(stack);
}
