#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


string express(long a, long b, long c, long d);
void express2(long a, long b, map<long,string> *m);
void express3(long a, long b, long c, map<long,string>* m);
void express4(long a, long b, long c, long d, map<long,string>* m);

int main(void){
  long a,b,c,d;

  while(1){
    cin>>a>>b>>c>>d;
    if(a==0 and b==0 and c==0 and d==0)break;
    cout<<express(a,b,c,d)<<endl;
  }
  return 0;
}


string express(long a, long b, long c, long d){
  vector<long> num;
  num.push_back(a);
  num.push_back(b);
  num.push_back(c);
  num.push_back(d);
  sort(num.begin(),num.end());
  do{
    map<long, string> m;
    express4(num[0],num[1],num[2],num[3],&m);
    for(auto iter=m.begin();iter!=m.end();iter++){
      auto key=iter->first;
      if(key==10)return m[key];
    }
  }while(next_permutation(num.begin(),num.end()));
  return "0";
}


void express2(long a, long b, map<long,string> *m){
  (*m)[a+b]=to_string(a)+" + "+to_string(b);
  (*m)[a-b]=to_string(a)+" - "+to_string(b);
  (*m)[a*b]=to_string(a)+" * "+to_string(b);
  (*m)[b-a]=to_string(b)+" - "+to_string(a);
}


void express3(long a,long b, long c, map<long,string>* m){
  map<long, string> m2;
  express2(b,c,&m2);
  for(auto iter=m2.begin();iter!=m2.end();iter++){
    auto key=iter->first;
    auto value=iter->second;
    (*m)[a+key]=to_string(a)+" + ("+value+")";
    (*m)[a-key]=to_string(a)+" - ("+value+")";
    (*m)[a*key]=to_string(a)+" * ("+value+")";
    (*m)[key-a]="("+value+") - "+to_string(a);
  }
}

void express4(long a, long b, long c, long d, map<long,string>* m){
  map<long, string> m3;
  express3(b,c,d,&m3);
  for(auto iter=m3.begin();iter!=m3.end();iter++){
    auto key=iter->first;
    auto value=iter->second;
    (*m)[a+key]=to_string(a)+" + ("+value+")";
    (*m)[a-key]=to_string(a)+" - ("+value+")";
    (*m)[a*key]=to_string(a)+" * ("+value+")";
    (*m)[key-a]="("+value+") - "+to_string(a);
  }

  map<long, string> m2a, m2b;
  express2(a,b,&m2a);
  express2(c,d,&m2b);
  for(auto iter1=m2a.begin();iter1!=m2a.end();iter1++){
    for(auto iter2=m2b.begin();iter2!=m2b.end();iter2++){
      auto key1=iter1->first;
      auto value1=iter1->second;
      auto key2=iter2->first;
      auto value2=iter2->second;
      (*m)[key1+key2]="("+value1+") + ("+value2+")";
      (*m)[key1-key2]="("+value1+") - ("+value2+")";
      (*m)[key1*key2]="("+value1+") * ("+value2+")";
      (*m)[key2-key1]="("+value2+") - ("+value1+")";
    }
  }
}
