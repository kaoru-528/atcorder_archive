#include <stdio.h>
int main(){
    int a[15][15] ={
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,0,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,1,0,1,1,1,1,1,1,1,0,1,0,1},
        {1,0,1,0,1,0,0,0,0,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,0,0,0,0,1,0,1,0,1},
        {1,0,1,0,1,1,1,1,1,1,1,0,1,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},        
    };
    int r,c;
    if(scanf("%d", &r) == 1);
    if(scanf("%d", &c) == 1);
    // scanf("%d", &r);
    // scanf("%d", &c);

    if (a[r-1][c-1] == 1){
        printf("black");
    }
    else{
        printf("white");
    }
    return 0;
}