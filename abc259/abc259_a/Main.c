#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, x, t, d;
    int a;

    if(scanf("%d", &n) == 1);
    if(scanf("%d", &m) == 1);
    if(scanf("%d", &x) == 1);
    if(scanf("%d", &t) == 1);
    if(scanf("%d", &d) == 1);
    if(m > x){
        if(x < n){
            a = t;
        }
        else{
            a = t + d*(x-n);

        }
    }
    else{
        if(m < n){
            if(n > x){
                a = t - d*(x-m); 
            }
            else{
                a = t + d*(m-n); 
            }
        }
        else{
            if(x <= n){
                a = t - d*(x-m);
            }
            else{
                a = t - d*(n-m);
            }
        }
    }

    printf("%d", a);
    return 0;
}