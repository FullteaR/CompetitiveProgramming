#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

struct List{
  long x;
  List* after;
  List* before;
}typedef List;

int main(void){

  List start;
  List end;
  start.before=&start;
  start.after=&end;
  start.x=0;
  end.before=&start;
  end.after=&end;
  end.x=0;
  List* ker = &end;

  long q;
  cin>>q;
  for(long i=0;i<q;i++){
    long ope;
    cin>>ope;
    if(ope==0){
      long x;
      cin>>x;
      List* l = new List;
      ker->before->after=l;
      l->before=ker->before;
      l->after=ker;
      ker->before=l;
      l->x=x;
      ker=l;
    }
    else if(ope==1){
      long d;
      cin>>d;
      if(d>0){
        for(long j=0;j<d;j++){
          ker=ker->after;
        }
      }
      else{
        for(long j=0;j<-1*d;j++){
          ker=ker->before;
        }
      }
    }
    else{//ope==2
      ker->before->after=ker->after;
      ker->after->before=ker->before;
      List* tmp=ker;
      ker=ker->after;
      free(tmp);
    }
    /*
    printf("kernel=%p\n",ker);
    for(List* iter=start.after;iter!=&end;iter=iter->after){
      printf("pointer=%p before=%p after=%p value=%ld\n",iter,iter->before,iter->after,iter->x);
    }
    cout<<endl;
    */
  }

  for(List* iter=start.after;iter!=&end;iter=iter->after){
    cout<<iter->x<<endl;
  }

  return 0;
}
