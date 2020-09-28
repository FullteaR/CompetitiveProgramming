#include <iostream>
#include <cstdio>
using namespace std;

int seven_digit(int n);
int bin(int n);

int main(void){
  while(1){
    int n, d, status;
    cin>>n;
    if(n==-1){return 0;}
    status=0;
    for(int i=0;i<n;i++){
      cin>>d;
      printf("%07d\n",bin(status^seven_digit(d)));
      status = seven_digit(d);
    }
  }
}

int seven_digit(int n){
  switch (n) {
    case 0:
      return 0b0111111;
    case 1:
      return 0b0000110;
    case 2:
      return 0b1011011;
    case 3:
      return 0b1001111;
    case 4:
      return 0b1100110;
    case 5:
      return 0b1101101;
    case 6:
      return 0b1111101;
    case 7:
      return 0b0100111;
    case 8:
      return 0b1111111;
    case 9:
      return 0b1101111;
    default:
      return -1;
  }
}

int bin(int n){
  int retval=0;
  int base=1;
  while(n>0){
    retval+=base*(n%2);
    n=n/2;
    base=base*10;
  }
  return retval;
}
