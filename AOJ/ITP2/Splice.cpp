#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <utility>

using namespace std;

struct List{
  long x;
  List* after;
  List* before;
}typedef List;

int main(void){
  long n,q;
  cin>>n>>q;

  auto L = new pair<List*,List*>[n];
  for(int i=0;i<n;i++){
    L[i].first = new List;
    L[i].second = new List;
    L[i].first->before=L[i].first;
    L[i].first->after=L[i].second;
    L[i].second->before=L[i].first;
    L[i].second->after=L[i].second;
  }
  for(long i=0;i<q;i++){
    long ope;
    cin>>ope;
    if(ope==0){
      long t,x;
      cin>>t>>x;
      auto end=L[t].second;
      List* l = new List;
      l->x=x;
      l->before=end->before;
      l->after=end;
      end->before->after=l;
      end->before=l;
    }
    else if(ope==1){
      long t;
      cin>>t;
      for(List* iter=L[t].first->after;iter->after!=iter;iter=iter->after){
        cout<<iter->x;
        if(iter->after->after!=iter->after){
          cout<<" ";
        }
      }
      cout<<endl;
    }
    else{//ope==2
      long s,t;
      cin>>s>>t;
      List *start_s, *end_s, *start_t, *end_t;
      start_s=L[s].first;
      end_s=L[s].second;
      start_t=L[t].first;
      end_t=L[t].second;
      if(start_s->after==end_s){
        continue;
      }
      end_t->before->after=start_s->after;
      end_t->before=end_s->before;
      start_s->after=end_s;
      end_s->before=start_s;
    }
  }
}
