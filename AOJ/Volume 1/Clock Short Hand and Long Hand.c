#include <stdio.h>
#include <math.h>

double longHand(int h, int m);
double shortHand(int h, int m);

int main(void){
  double al,as;
  int n,h,m;
  double d;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d:%d",&h,&m);
    al=longHand(h,m);
    as=shortHand(h,m);
    d=fabs(as-al);
    if(d>180){
      d=360-d;
    }

    if(d<30){
      printf("alert\n");
    }
    else if(d>=90){
      printf("safe\n");
    }
    else{
      printf("warning\n");
    }
  }
  return 0;
}

double longHand(int h, int m){
  return 360.0*m/60;
}

double shortHand(int h, int m){
  return 360.0*h/12+30.0*m/60;
}
