#include <stdio.h>
#include <stdlib.h>

int main(void){
    int k;
    int count = 0;

    if(scanf("%d", &k) == 1);
    
    while(1){
        if(k <60){
            break;
        }
        else{
            k -= 60;
            count++;
        }
    };

    if(k <10){
        printf("%d:0%d", 21+count, k);
    }
    else{
        printf("%d:%d", 21+count, k);
    }
    return 0;
}