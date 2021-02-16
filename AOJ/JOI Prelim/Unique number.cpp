#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void){
  int N;
  cin>>N;
  map<int,int> g1,g2,g3;
  vector<int> v1,v2,v3;
  for(int i=1;i<=100;i++){
    g1[i]=0;
    g2[i]=0;
    g3[i]=0;
  }
  for(int i=0;i<N;i++){
    int s1,s2,s3;
    cin>>s1>>s2>>s3;
    v1.push_back(s1);
    v2.push_back(s2);
    v3.push_back(s3);
    g1[s1]++;
    g2[s2]++;
    g3[s3]++;
  }
  for(int i=0;i<N;i++){
    int score=0;
    if(g1[v1[i]]==1){
      score+=v1[i];
    }
    if(g2[v2[i]]==1){
      score+=v2[i];
    }
    if(g3[v3[i]]==1){
      score+=v3[i];
    }
    cout<<score<<endl;
  }
  return 0;
}
