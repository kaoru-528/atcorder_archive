#include<stdio.h>

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    if((a * b) % 2 == 0 ){
        printf("Even");
    }
    if((a * b) % 2 == 1 ){
        printf("Odd");
    } 
    return 0;
}