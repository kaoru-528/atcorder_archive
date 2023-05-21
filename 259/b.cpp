#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main(){
    double x, y, a, b;
    int c;

    if(scanf("%lf", &x) == 1);
    if(scanf("%lf", &y) == 1);
    if(scanf("%d", &c) == 1);

    double s;
    s =  c/180 * M_PI;
    if(s == M_PI){
        a = x*cos(a);
        b = y*cos(s);
        
    }
    else{
    a = x*cos(a) - y*sin(s);
    b = x*sin(a) + y*cos(s);
    }
    

    printf("%g %g", a, b);
    return 0;
}