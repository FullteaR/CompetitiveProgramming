#include <iostream>
#include <cstring>
using namespace std;

int dot(int a0, int a1, int a2, int a3,int a4, int a5, int a6, int a7, int p0, int p1,int p2, int p3, int p4, int p5, int p6, int p7);

int main(void){
  int p0,p1,p2,p3,p4,p5,p6,p7;
  while(cin>>p0>>p1>>p2>>p3>>p4>>p5>>p6>>p7){
    int retval=1000000010;
    int array[8];
    {
      int _array[8]={4,1,4,1,2,1,2,1};
      if(dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7)<=retval){
        for(int i=0;i<8;i++){
          array[i]=_array[i];
        }
        retval=dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7);
      }
    }

    {
      int _array[8]={4,1,2,1,2,1,4,1};
      if(dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7)<=retval){
        for(int i=0;i<8;i++){
          array[i]=_array[i];
        }
        retval=dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7);
      }
    }

    {
      int _array[8]={2,1,4,1,4,1,2,1};
      if(dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7)<=retval){
        for(int i=0;i<8;i++){
          array[i]=_array[i];
        }
        retval=dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7);
      }
    }

    {
      int _array[8]={2,1,2,1,4,1,4,1};
      if(dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7)<=retval){
        for(int i=0;i<8;i++){
          array[i]=_array[i];
        }
        retval=dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7);
      }
    }

    {
      int _array[8]={1,4,1,4,1,2,1,2};
      if(dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7)<=retval){
        for(int i=0;i<8;i++){
          array[i]=_array[i];
        }
        retval=dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7);
      }
    }

    {
      int _array[8]={1,4,1,2,1,2,1,4};
      if(dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7)<=retval){
        for(int i=0;i<8;i++){
          array[i]=_array[i];
        }
        retval=dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7);
      }
    }

    {
      int _array[8]={1,2,1,4,1,4,1,2};
      if(dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7)<=retval){
        for(int i=0;i<8;i++){
          array[i]=_array[i];
        }
        retval=dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7);
      }
    }

    {
      int _array[8]={1,2,1,2,1,4,1,4};
      if(dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7)<=retval){
        for(int i=0;i<8;i++){
          array[i]=_array[i];
        }
        retval=dot(_array[0],_array[1],_array[2],_array[3],_array[4],_array[5],_array[6],_array[7],p0,p1,p2,p3,p4,p5,p6,p7);
      }
    }
    for(int i=0;i<7;i++){
      cout<<array[i]<<" ";
    }
    cout<<array[7]<<endl;
  }
  return 0;
}


int dot(int a0, int a1, int a2, int a3,int a4, int a5, int a6, int a7, int p0, int p1,int p2, int p3, int p4, int p5, int p6, int p7){
  int retval=0;
  retval+=a0-min(p0,a0);
  retval+=a1-min(p1,a1);
  retval+=a2-min(p2,a2);
  retval+=a3-min(p3,a3);
  retval+=a4-min(p4,a4);
  retval+=a5-min(p5,a5);
  retval+=a6-min(p6,a6);
  retval+=a7-min(p7,a7);
  return retval;
}
