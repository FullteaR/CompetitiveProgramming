#include <iostream>
#include <cstdio>
#include <stdlib.h>
#pragma GCC optimize("Ofast")

using namespace std;
#define INF 1000000100


struct List{
  long x;
  List* after;
  List* before;
}typedef List;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  List* start = new List;
  List* end = new List;
  start->before=start;
  start->after=end;
  start->x=INF;
  end->before=start;
  end->after=end;
  end->x=INF;
  long n;
  cin>>n;
  for(long i=0;i<n;i++){
    string command;
    cin>>command;
    if(command=="insert"){
      long x;
      cin>>x;
      List* l = new List;
      l->before=start;
      l->after=start->after;
      start->after->before=l;
      start->after=l;
      l->x=x;
    }
    else if(command=="delete"){
      long x;
      cin>>x;
      for(List* iter=start;iter!=end;iter=iter->after){
        if(iter->x==x){
          iter->after->before=iter->before;
          iter->before->after=iter->after;
          free(iter);
          break;
        }
      }
    }
    else if(command=="deleteFirst"){
      List* first=start->after;
      start->after=first->after;
      first->after->before=start;
      free(first);
    }
    else{
      List* last=end->before;
      end->before=last->before;
      last->before->after=end;
      free(last);
    }
  }

  for(List* iter=start->after;iter!=end;iter=iter->after){
    printf("%ld",iter->x);
    if(iter->after!=end){
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}
