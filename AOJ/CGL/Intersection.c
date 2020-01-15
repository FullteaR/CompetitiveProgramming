#include <stdio.h>


int max(int a, int b);
int min(int a, int b);

int main(void){
  int q;
  scanf("%d",&q);

  double x1,y1,x2,y2,x3,y3,x4,y4;
  double x,y;//直線の交点
  double det;//行列式
  double k1,k2;
  int a,b,c,d;
  for(int i=0;i<q;i++){
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    det=(x2-x1)*(y4-y3)-(y2-y1)*(x4-x3);
    if(det==0){//平行
      if(x1*y2-x2*y1!=x3*y4-x4*y3){
        printf("0\n");
        continue;
      }


      if(x2==x1){
        a=min(y1,y2);
        b=max(y1,y2);
        c=min(y3,y4);
        d=max(y3,y4);
      }
      else{
        a=min(x1,x2);
        b=max(x1,x2);
        c=min(x3,x4);
        d=max(x3,x4);
      }

      if(b<c || d<a){
        printf("0\n");
      }
      else{
        printf("1\n");
      }
      continue;
    }
    x=((x3-x4)*(x1*y2-x2*y1)+(x2-x1)*(x3*y4-x4*y3))/det;
    y=((y3-y4)*(x1*y2-x2*y1)+(y2-y1)*(x3*y4-x4*y3))/det;
    if(x1==x2){
      k1=(y-y1)*1.0/(y2-y1);
    }
    else{
      k1=(x-x1)*1.0/(x2-x1);
    }
    if(k1<0 || 1<k1){
      printf("0\n");
      continue;
    }

    if(x3==x4){
      k2=(y-y3)*1.0/(y4-y3);
    }
    else{
      k2=(x-x3)*1.0/(x4-x3);
    }
    if(k2<0 || 1<k2){
      printf("0\n");
      continue;
    }
    printf("1\n");
  }
  return 0;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
