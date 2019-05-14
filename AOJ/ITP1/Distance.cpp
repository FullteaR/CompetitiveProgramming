using namespace std;
#include <math.h>
#include <stdio.h>

int main(void){
        double x1,y1,x2,y2;
        scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
        printf("%lf",sqrt((y1-y2)*(y1-y2)+(x1-x2)*(x1-x2)));
        return 0;
}
