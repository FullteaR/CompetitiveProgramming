#include <cstdio>
using namespace std;

int main(void){
  int N;
  scanf("%d",&N);
  printf("%02d:%02d:%02d\n",N/3600,(N/60)%60,N%60);
  return 0;
}
