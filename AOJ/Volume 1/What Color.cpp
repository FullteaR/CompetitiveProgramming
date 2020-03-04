#include <map>
#include <iostream>
#include <cmath>
using namespace std;

string near(int R, int G, int B);

double dist(int R1, int G1, int B1, int R2, int G2, int B2);

int main(void){
  map<char,int> d;
  for(int i=0;i<10;i++){
    d[i+'0']=i;
  }
  for(int i=0;i<6;i++){
    d[i+'a']=i+10;
  }
  string s;
  int R,G,B;
  while(1){
    cin>>s;
    if(s=="0")break;
    R=d[s[1]]*16+d[s[2]];
    G=d[s[3]]*16+d[s[4]];
    B=d[s[5]]*16+d[s[6]];
    cout<<near(R,G,B)<<endl;
  }
  return 0;
}

string near(int R, int G, int B){
  double distance=10000;
  string color="hoge";
  if(dist(R,G,B,0,0,0)<distance){
    color="black";
    distance=dist(R,G,B,0,0,0);
  }
  if(dist(R,G,B,0,0,255)<distance){
    color="blue";
    distance=dist(R,G,B,0,0,255);
  }
  if(dist(R,G,B,0,255,0)<distance){
    color="lime";
    distance=dist(R,G,B,0,255,0);
  }
  if(dist(R,G,B,0,255,255)<distance){
    color="aqua";
    distance=dist(R,G,B,0,255,255);
  }
  if(dist(R,G,B,255,0,0)<distance){
    color="red";
    distance=dist(R,G,B,255,0,0);
  }
  if(dist(R,G,B,255,0,255)<distance){
    color="fuchsia";
    distance=dist(R,G,B,255,0,255);
  }
  if(dist(R,G,B,255,255,0)<distance){
    color="yellow";
    distance=dist(R,G,B,255,255,0);
  }
  if(dist(R,G,B,255,255,255)<distance){
    color="white";
    distance=dist(R,G,B,255,255,255);
  }
  return color;
}

double dist(int R1, int G1, int B1, int R2, int G2, int B2){
  return sqrt((R1-R2)*(R1-R2)+(G1-G2)*(G1-G2)+(B1-B2)*(B1-B2));
}
